#include <filesystem>

class recursive_directory_iterator_ext: public std::filesystem::recursive_directory_iterator
{
public:
	recursive_directory_iterator_ext(const std::filesystem::path path, const std::string extension);
	recursive_directory_iterator_ext begin();
	std::filesystem::recursive_directory_iterator end();
	recursive_directory_iterator_ext& operator++();
private:
	std::string extension;
};