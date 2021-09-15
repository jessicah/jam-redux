#pragma once

#include <functional>
#include <string>

void file_dirscan(const std::string &directory, const std::function<void (const std::string &)>& callback);
