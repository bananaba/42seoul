#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void	replaceStr(std::string &content, std::string s1, std::string s2)
{
	int	len1;
	int	len2;
	int	i;

	len1 = content.length();
	len2 = s1.length();
	i = 0;
	while (i + len2 <= len1)
	{
		if (content.compare(i, len2, s1) == 0)
		{
			content.erase(i, len2);
			content.insert(i, s2);
			len1 = content.length();
			i += s2.length();
		}
		i++;
	}
}

int	exitErr(std::string str)
{
	std::cerr << "Error: " << str << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string			content;
	std::stringstream	ss;

	if (argc != 4)
		return (exitErr("Usage: ./Replacer <filename> s1 s2"));
	else if (argv[2][0] == '\0')
		return (exitErr("s1 is empty"));
	ifs.open(argv[1], std::ios_base::in);
	if (ifs.fail())
		return (exitErr("input file open fail"));
	ss << ifs.rdbuf();
	ifs.close();
	ofs.open(static_cast<std::string>(argv[1]) + ".replace", std::ios_base::out | std::ios_base::trunc);
	if (ofs.fail())
		return (exitErr("output file open fail"));
	content = ss.str();
	replaceStr(content, argv[2], argv[3]);
	ofs << content;
	ofs.close();
	return (0);
}
