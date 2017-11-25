/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "LoadCommand.h"
#include "render/StateLayer.h"

namespace engine{
    
    LoadCommand::LoadCommand(const std::string& mapCSV, const std::string& gridCSV) {
        this->file_name_map = file_name_map;
        this->file_name_grid = file_name_grid;
    }
    
    const std::string& LoadCommand::getFile_name_grid() const {
        return this->file_name_grid;
    }
    
    const std::string& LoadCommand::getFile_name_map() const {
        return this->file_name_map;
    }
    
    void LoadCommand::setFile_name_grid(const std::string& file_name_grid) {
        this->file_name_grid = file_name_grid;
    }
    
    void LoadCommand::setFile_name_map(const std::string& file_name_map) {
        this->file_name_map = file_name_map;
    }

    CommandTypeId LoadCommand::getTypeId() const {
        return CommandTypeId::LOAD;
    }
    
    void LoadCommand::execute(state::State& state) {
        state.getTerrain().load(file_name_map, 1);
        state.getGrid().load(file_name_grid, 2);
    }

}
