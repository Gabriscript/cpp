#pragma once

template<typename T, typename F >
void iter(T array[], int len, F f)
{
	if(!array)
		return;

	for (auto i = 0; i < len; i++)
		f(array[i]);
}