#include "httplib.h"
#include "splay_tree.h"

int main(){
    httplib::Server backend;

    STree history;
    history.insert("test");
    history.insert("hello");
    history.insert("check");
    history.insert("new");

    backend.Get("/get_tree", [&](const httplib::Request& /*req*/, httplib::Response &res) {
        res.set_content(history.toJson(), "application/json");
    });
    
    backend.listen("localhost",8080);

}