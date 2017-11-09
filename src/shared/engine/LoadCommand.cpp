/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "LoadCommand.h"

namespace engine{

    LoadCommand::LoadCommand() {
        file_name="";
    }

    void LoadCommand::execute(state::State& state) {
        LoadCommand();
    }

    const std::string& LoadCommand::getFile_name() const {
        return file_name;
    }

    CommandTypeId LoadCommand::getTypeId() const {
        return CommandTypeId::LOAD;
    }

    void LoadCommand::setFile_name(const std::string& file_name) {
        this->file_name=file_name;
    }

}
