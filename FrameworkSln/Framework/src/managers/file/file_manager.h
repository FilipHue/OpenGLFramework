#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <filesystem>

class FileManager
{
public:
	static void GetShaderFiles(
		std::string root_folder,
		std::unordered_map<std::string, std::string> &vertex_files,
		std::unordered_map<std::string, std::string> &fragment_files);

private:
	FileManager() = delete;

private:
	const static std::string c_delimiter;
};
