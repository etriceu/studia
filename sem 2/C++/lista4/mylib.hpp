namespace my
{
	template <typename T>
	size_t min(T tab, size_t size)
	{
		size_t x = 0;
		for(size_t n = 0; n < size; n++)
			if(tab[x] > tab[n])
				x = n;

		return x;
	}
	
	template <typename T>
	size_t max(T tab, size_t size)
	{
		size_t x = 0;
		for(size_t n = 0; n < size; n++)
			if(tab[x] < tab[n])
				x = n;

		return x;
	}
	
	template <typename T, typename F>
	size_t find(T tab, size_t size, F find)
	{
		for(size_t n = 0; n < size; n++)
			if(find == tab[n])
				return n;

		return 0;
	}
	
	template <typename T, typename F>
	void loop2d(T &tab, size_t width, size_t height, F func)
	{
		for(size_t y = 0; y < height; y++)
			for(size_t x = 0; x < width; x++)
				func(tab, x, y);
	}
};
