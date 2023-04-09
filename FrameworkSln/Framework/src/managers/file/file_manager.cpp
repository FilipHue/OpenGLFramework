#include "file_manager.h"

const std::string FileManager::c_delimiter = "\\";

void FileManager::GetShaderFiles(
    std::string root_folder,
    std::unordered_map<std::string, std::string> &vertex_files,
    std::unordered_map<std::string, std::string> &fragment_files)
{
    std::string vertex_file;
    std::string fragment_file;
    std::string shader_name;

    for (const auto& entry : std::filesystem::directory_iterator(root_folder)) {
        if (std::filesystem::is_directory(entry.path())) {
            auto folder_iter = std::filesystem::directory_iterator(entry);
            fragment_file = (*folder_iter).path().filename().string();
            folder_iter++;
            vertex_file = (*folder_iter).path().filename().string();


            shader_name = vertex_file.substr(0, vertex_file.find("_"));
            shader_name += "Shader";
            shader_name[0] = toupper(shader_name[0]);

            vertex_file = root_folder + c_delimiter + entry.path().filename().string() + c_delimiter + vertex_file;
            fragment_file = root_folder + c_delimiter + entry.path().filename().string() + c_delimiter + fragment_file;

            vertex_files[shader_name] = vertex_file;
            fragment_files[shader_name] = fragment_file;
        }
    }
}
