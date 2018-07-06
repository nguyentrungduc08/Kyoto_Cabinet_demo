/* 
 * File:   main.cpp
 * Author: cpu10664-local
 *
 * Created on July 4, 2018, 11:21 AM
 */
#include <bits/stdc++.h>
#include <cstdlib>
#include <kchashdb.h>

using namespace std;
using namespace kyotocabinet;

/*
 * 
 */

int main(int argc, char** argv) {
    HashDB db;

    if (db.open("dbID.kch", HashDB::OWRITER | HashDB::OCREATE)) {
        std::cout << "open KC database success" << std::endl;
    } else {
        std::cerr << "open error: " << db.error().name() << std::endl;
    }

    string key = "key4";
    string value = "value422";
    
//    db.set(key,value);
    db.add(key, value);
    
    string res;
    db.get(key, &res);
    
    cout << "output: " << res << endl;
    cout << "total records: " << db.count() << endl;
    
    
    if (db.close()) {
        std::cout << "close KC database success" << std::endl;
    } else {
        std::cerr << "close error: " << db.error().name() << std::endl;
    }
    return 0;
}

