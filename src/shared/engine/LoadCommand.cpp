/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "LoadCommand.h"
#include "render/StateLayer.h"


namespace engine{

    LoadCommand::LoadCommand(const std::string& mapCSV, const std::string& gridCSV) {
        this->file_name_map = mapCSV;
        this->file_name_grid = gridCSV;
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
    
    void LoadCommand::execute(state::State& state,std::stack<Action*>& s) {
        state.getTerrain().load(file_name_map, 1);
        state.getGrid().load(file_name_grid, 2);
    }
    
    void LoadCommand::serialized(Json::Value& out) const {  
    
        out["name_map"] = file_name_map;
        out["name_grid"] = file_name_grid;
    }

    LoadCommand* LoadCommand::deserialized(Json::Value& in) {
        file_name_map = in.get("name_map","").asString();
        file_name_grid = in.get("name_grid","").asString();
        return new LoadCommand("name_map","name_grid");
    }
    /*{
        "name_grid" : "res/mapEngine.csv",
        "name_map" : "res/mapEngine_Grid.csv",
    }*/
    
}
