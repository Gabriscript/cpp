/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:01:18 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/04 14:28:05 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>



static std::string Replace(std::string line, std::string find, std::string replace)
{
	  if (find.empty())
	  	return line;
		
	size_t pos = 0;
	while((pos = line.find(find, pos)) != std::string::npos)
	{
		line.erase(pos, find.length());
		line.insert(pos, replace);
		pos += replace.length();		
	}
	return line;
}

int main(int ac,char **av)
{
	if (ac != 4)
		return (std::cout << "Wrong number of arguments" << std::endl, 0);
		
	std::string fileName = av[1]; 
	std::string newFileName = fileName + ".replace"; 
	
	
    std::ifstream inputFile(av[1]);
	std::ofstream outputFile(newFileName);
    if (!inputFile || !outputFile)
    {
		std::cerr << "Failed to open  file!" << std::endl;
        return 1;
    }
	std::string line;
	while(std::getline(inputFile,line))
	{
		std::string newLine = Replace(line, av[2], av[3]);
		outputFile << newLine;
		if (!inputFile.eof())
            outputFile << std::endl; 
	}

	(inputFile).close();
	(outputFile).close();
	return 0;
}
