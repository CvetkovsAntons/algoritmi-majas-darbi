#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_CONSTANTS_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_CONSTANTS_H

#include <iostream>
using namespace std;

const string M_MAIN = "main";
const string M_HELP = "help";

const char I_HELP = 'h';
const char I_NEW = '+';
const char I_DELETE = '-';
const char I_SHOW = '*';
const char I_EXIT = '$';

const string T_FILE = "f";
const string T_DIRECTORY = "d";
const string T_DISK = "Disk";

const string ERR_INCORRECT_INPUT = "ERROR!!! Incorrect input";
const string ERR_NOT_A_NUMBER = "ERROR!!! Not a number";
const string ERR_NODE_NOT_FOUND = "ERROR!!! Node not found";
const string ERR_PARENT_NODE_NOT_FOUND = "ERROR!!! Parent node not found";
const string ERR_INCORRECT_TYPE = "ERROR!!! Incorrect type";
const string ERR_PARENT_IN_NOT_A_FOLDER = "ERROR!!! Parent is not a folder";
const string ERR_DUPLICATE_WITH_DIFFERENT_TYPE = "ERROR!!! Duplicate with different type exists";
const string ERR_NEW_NODE_EMPTY_NAME = "ERROR!!! Name is required";
const string ERR_DELETE_DISK = "ERROR!!! Deleting root disk isn't allowed";

#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_CONSTANTS_H
