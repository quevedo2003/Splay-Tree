#include "httplib.h"
#include "splay_tree.h"

int main(){
    httplib::Server backend;
    STree history;


    // backend.Get("/get_tree", [&](const httplib::Request& /*req*/, httplib::Response &res) {
    //     res.set_content(history, "application/json")
    // })
    
    backend.listen("localhost",8080);

}