#include "filesystem.h"

recursive_directory_iterator_ext::recursive_directory_iterator_ext(const std::filesystem::path path, const std::string extension) :
	std::filesystem::recursive_directory_iterator(path, std::filesystem::directory_options::follow_directory_symlink),
	extension(extension)
{
}

recursive_directory_iterator_ext& recursive_directory_iterator_ext::operator++()
{
	do {
		std::filesystem::recursive_directory_iterator::operator++();
	} while(*this != end() && (*this)->path().extension().compare(extension));
	return *this;
}

recursive_directory_iterator_ext recursive_directory_iterator_ext::begin()
{
	if((*this)->path().extension().compare(extension)) {
		return this->operator++();
	}
	return *this;
}

std::filesystem::recursive_directory_iterator recursive_directory_iterator_ext::end()
{
	return std::filesystem::recursive_directory_iterator();
}