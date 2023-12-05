#include "httplib.h"
#include "splay_tree.h"

int main(int argc, char *argv[]){
    httplib::Server backend;

    STree history;

    if(argc == 1){
        
    }

    backend.Get("/get_tree", [&](const httplib::Request& /*req*/, httplib::Response &res) {
        res.set_content(history.toJson(), "application/json");
    });

    // backend.Get("/search_tree", [&](const httplib::Request& req, httplib::Response &res) {
    //     std::string query = req.get_param_value("query");
    //     history.splaySearch(query);
    //     std::string root_url = history.get_root();
    //     if(root_url != query){
    //         history.insert(query);
    //     }
    //     res.set_content(history.toJson(), "application/json");
    // });
    
    backend.listen("localhost",8080);

}