//
// Created by ori on 12/26/18.
//

#ifndef ADVPROGRAMINGPROJECT1_MASTER_ENTERC_H
#define ADVPROGRAMINGPROJECT1_MASTER_ENTERC_H

#include <iostream>
#include "Command.h"

class Enterc: public Command{
public:
    int doCommand(vector<vector<string>> param) override {
        char x;
        cin>>x;
        return 1;
    }
};
#endif //ADVPROGRAMINGPROJECT1_MASTER_ENTERC_H
