const fs = require('fs');

nextID = 0;
warn = document.getElementById("warn");
tHtml = document.getElementById("table");
const columns = 9;
tData = [], tChain = [], indexes = [];

function clearHTMLTable() {
	for(var n = 0; n < tData.length; n++) {
		element = document.getElementById(String(tData[n][0]));
		if(element != null)
			element.remove();
	}
}

function insertHtml(t) {
	str = "<tr id=\"" + t[0] + "\"><td>" + t[0]; 
	for(n = 1; n < columns; n++)
		str += "</td><td>" + t[n];
	str += "</td></tr>";
	tHtml.innerHTML += str;
}

function insert(t) {
	warn.innerHTML = "";
	if(t[1] == ""){ warn.innerHTML = "Name: value can't be empty."; return;}
	else if(t[2] == ""){ warn.innerHTML = "Manufacturer: value can't be empty."; return;}
	else if(t[3] <= 0 || t[3] == ""){ warn.innerHTML = "Cores: value must be positive and integer."; return;}
	else if(t[4] <= 0 || t[4] == ""){ warn.innerHTML = "Memory: value must be positive and integer."; return;}
	else if(t[5] <= 0 || t[5] == ""){ warn.innerHTML = "Clock: value must be positive and integer."; return;}
	else if(t[6] <= 0 || t[6] == ""){ warn.innerHTML = "PSU: value must be positive and integer."; return;}
	insertHtml(t);
	tData.push(t);
	nextID++;
}

function clickInsert() {
	insert([nextID, document.getElementById("Name").value, document.getElementById("Manufacturer").value, document.getElementById("Cores").value, document.getElementById("Memory").value, document.getElementById("Clock").value, document.getElementById("PSU").value, document.getElementById("Parallel").checked, document.getElementById("Open").checked]);
}

function remove() {
	id = document.getElementById("ID").value;
	warn.innerHTML = "";
	if(id == "" || id < 0){ warn.innerHTML = "ID: value can't be negative or empty."; return;}
	document.getElementById(String(id)).remove();
	for(var n = 0; n < tData.length; n++)
		if(String(tData[n][0]) == String(id)) {
			tData.splice(n, 1);
			break;
		}
}

function save() {
	str = "";
	for(var n = 0; n < tData.length; n++)
		for(var i = 0; i < columns; i++)
			str += tData[n][i]+"\n";
	fs.writeFile("data.txt", str, (err) => {});
}

function load() {
	lines = fs.readFileSync("data.txt").toString().split("\n");
	clearHTMLTable();
	tData = [], str = "", max = 0;
	for(let n = 0; n < lines.length-1; n += columns) {
		nextID = lines[n]*1+1;
		t = lines.slice(n, n+columns);
		tData.push(t);
		insertHtml(t);
		if(max < nextID) max = nextID;
	}
	nextID = max;
}

function randomText() {
	const alphabet = 'abcdefghijklmnoprstuwz';
	let text = '';
	for(let i=0; i< 5; i++)
		text += alphabet.charAt(Math.round(Math.random() * alphabet.length));
	return text;
}

function random() {
	count = document.getElementById("Count").value;
	if(count <= 0 || count == ""){ warn.innerHTML = "Count: value must be positive and integer."; return;}
	let last = [], end = [], str = "";
	for(let n = 0; n < columns; n++) {
		indexes.push(new Map());
		last.push(new Map());
	}
	for(let n = 0; n < count; n++) {
		t = [nextID, randomText(), randomText(), Math.round(Math.random() * 100+1), Math.round(Math.random() * 100+1), Math.round(Math.random() * 100+1), Math.round(Math.random() * 100+1), Math.random() > 0.5 ? true : false, Math.random() > 0.5 ? true : false];
		insert(t);
		tChain.push(new Array(columns));
		for(let m = 1; m < columns; m++) {
			tChain[n][m] = -1;
			if(!indexes[m].has(String(t[m]))) indexes[m].set(String(t[m]), n);
			else tChain[last[m].get(String(t[m]))][m] = n;
			last[m].set(String(t[m]), n);
		}
	}
	for(let i = 0; i < tChain.length; i++) {
		str += "<td>" + tChain[i][1];
		for(let n = 2; n < columns; n++)
			str += "</td><td>" + tChain[i][n];
		str += "</td></tr>";
	}
	document.getElementById("table2").innerHTML = str;
}

function search() {
	value1 = String(document.getElementById("searchName1").value);
	column1 = document.getElementById("typeSearch1").value;
	value2 = String(document.getElementById("searchName2").value);
	column2 = document.getElementById("typeSearch2").value;
	clearHTMLTable();
	for(var n = 0; n < tData.length; n++)
		if((String(tData[n][column1]) == value1 || column1 == -1) && (column2 == -1 || String(tData[n][column2]) == value2))
			insertHtml(tData[n]);
}

function binarySearch() {
	value1 = String(document.getElementById("searchName1").value);
	column1 = document.getElementById("typeSearch1").value;
	clearHTMLTable();
	tData.sort(function(a, b){
		if(String(a[column1]) < String(b[column1])) return -1;
		else if(String(a[column1]) > String(b[column1])) return 1;
		return 0;});
	beg = 0, end = tData.length - 1;
	while (beg <= end) {
		m = Math.floor((beg+end)/2);
		if(String(tData[m][column1]) == value1) {
			for(var x = m; x < tData.length && String(tData[x][column1]) == value1; x++)
				insertHtml(tData[x]);
			for(var x = m-1; x >= 0 && String(tData[x][column1]) == value1; x--)
				insertHtml(tData[x]);
			break;
		} else if(String(tData[m][column1]) < value1) beg = m + 1;
		else end = m - 1;
	}
}

function chainSearch() {
	value1 = String(document.getElementById("searchName1").value);
	column1 = document.getElementById("typeSearch1").value;
	clearHTMLTable();
	for(let i = indexes[column1].get(value1); i != -1; i = tChain[i][column1])
		insertHtml(tData[i]);
}
