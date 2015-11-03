#pragma once
#ifndef MESSMER_CRYFS_CLI_H
#define MESSMER_CRYFS_CLI_H

#include "program_options/ProgramOptions.h"
#include "config/CryConfigFile.h"
#include <boost/filesystem/path.hpp>
#include <messmer/cpp-utils/tempfile/TempFile.h>
#include <messmer/cpp-utils/random/RandomGenerator.h>

namespace cryfs {
    class Cli final {
    public:
        Cli(cpputils::RandomGenerator &keyGenerator);
        int main(int argc, char *argv[]);

    private:
        void _runFilesystem(const program_options::ProgramOptions &options);
        CryConfigFile _loadOrCreateConfig(const program_options::ProgramOptions &options);
        boost::filesystem::path _determineConfigFile(const program_options::ProgramOptions &options);
        std::string _getPassword(const program_options::ProgramOptions &options);
        std::string _askPassword();
        bool _checkPassword(const std::string &password);
        void _showVersion();
        void _initLogfile(const program_options::ProgramOptions &options);
        void _sanityChecks(const program_options::ProgramOptions &options);
        void _checkMountdirDoesntContainBasedir(const program_options::ProgramOptions &options);
        bool _pathContains(const boost::filesystem::path &parent, const boost::filesystem::path &child);
        void _checkDirAccessible(const boost::filesystem::path &dir, const std::string &name);
        std::shared_ptr<cpputils::TempFile> _checkDirWriteable(const boost::filesystem::path &dir, const std::string &name);
        void _checkDirReadable(const boost::filesystem::path &dir, std::shared_ptr<cpputils::TempFile> tempfile, const std::string &name);

        cpputils::RandomGenerator &_keyGenerator;
    };
}

#endif