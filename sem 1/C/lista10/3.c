//pewnie przesadzone ale tez nie bardzo wiedzialem jak interpretowac tresc zadania

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char imie[30];
	char nazwisko[50];
	short wiek;
	char PESEL[11];
	char email[50];
} tperson;

typedef struct
{
	tperson person;
	void *next;
} List;

List *list = NULL, *last;

void add()
{
	List *tmp = (List*)malloc(sizeof(List));
	printf("imie: "); scanf("%s", tmp->person.imie);
	printf("nazwisko: "); scanf("%s", tmp->person.nazwisko);
	printf("wiek: "); scanf("%d", &tmp->person.wiek);
	printf("PESEL: "); scanf("%s", tmp->person.PESEL);
	printf("email: "); scanf("%s", tmp->person.email);
	tmp->next = NULL;
	
	if(list == NULL)
		list = tmp;
	else
		last->next = tmp;

	last = tmp;
}

void show(int id)
{
	int n = 0;
	for(List *obj = list; obj != NULL; obj = (List*)obj->next, n++)
		if(n == id || id == -1)
		{
			if(id == -1)
				printf("\nid: %d", n);
			printf(	"\nimie: %s\nnazwisko: %s\nwiek: %d\nPESEL: %.11s\nemail: %s\n",
					obj->person.imie, obj->person.nazwisko, obj->person.wiek,
					obj->person.PESEL, obj->person.email);
			if(id != -1)
				break;
		}
}

void remove(int id)
{
	int n = 0;
	for(List *obj = list, *old = list; obj != NULL; old = obj, obj = (List*)obj->next, n++)
		if(n == id || id == -1)
		{
			if(last == obj)
				last = n ? last = old : NULL;
				
			if(n == 0)
			{
				list = (List*)obj->next;
				free(obj);
				obj = list;
				if(obj == NULL)
					break;
			}
			else
			{
				old->next = obj->next;
				free(obj);
				obj = (List*)old->next;
			}
			if(id != -1)
				break;
		}
}

void save()
{
	FILE *file = fopen("database.db", "wb");
	
	for(List *obj = list; obj != NULL; obj = (List*)obj->next)
		fwrite(&obj->person, sizeof(tperson), 1, file);
	
	fclose(file);
}

void read()
{
	FILE *file = fopen("database.db", "rb");
	if(file == NULL)
		return;
	
	while(1)
	{
		tperson person;
		fread(&person, sizeof(tperson), 1, file);
		if(feof(file))
			break;
		printf(	"\nimie: %s\nnazwisko: %s\nwiek: %d\nPESEL: %.11s\nemail: %s\n",
					person.imie, person.nazwisko, person.wiek,
					person.PESEL, person.email);
	}
	fclose(file);
}

int main()
{
	printf("commands: add, remove [id], show [id], save, read, exit\n");
	printf("(gdy id = -1 to wyszukuje wszystko)\n");
	char cmd[32];
	int id;
	do
	{
		printf("\n> ");
		scanf("%s", cmd);
		if(!strcmp(cmd, "add")) add();
		else if(!strcmp(cmd, "save")) save();
		else if(!strcmp(cmd, "read")) read();
		else if(!strcmp(cmd, "show"))
		{
			scanf("%d", &id);
			show(id);
		}
		else if(!strcmp(cmd, "remove"))
		{
			scanf("%d", &id);
			remove(id);
		}
	} while(strcmp(cmd, "exit"));
	
	remove(-1);
	
	return 0;
}
