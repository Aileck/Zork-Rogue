#include "InputProcessor.h"
#include <cctype>

bool InputProcessor::ProcessInput(string input, Scene* scene, Hero* hero)
{
    {
        //Input to lowercase
        string lower_input;
        for (char c : input) {
            lower_input += tolower(c);
        }

        //Split user token to two parts, action + target
        stringstream ss(lower_input);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string action = words[0];
        string target;
        for (int i = 1; i < words.size(); ++i) {
            target += words[i];
            if (i != words.size() - 1) {
                target += " ";
            }
        }
        
        InputType actiontype = InputToType(action);

        switch (actiontype)
        {
            case InputProcessor::CHECK:
                Check(scene,target);
                break;
            case InputProcessor::GOTO:
                break;
            case InputProcessor::ATTACK:
                break;
            case InputProcessor::TALK:
                break;
            case InputProcessor::INVENTORY:
                break;
            case InputProcessor::USE:
                break;
            case InputProcessor::PICK:
                break;
            case InputProcessor::HELP:
                break;
            case InputProcessor::NOTREGISTERED:
                cout << "This is not a valid command." << endl;
                break;
            default:
                break;
        }

        return true;
    }
}

InputProcessor::InputType InputProcessor::InputToType(string s)
{
    if (s == "check" || "c") {
        return CHECK;
    }
    if (s == "goto" || "go") {
        return GOTO;
    }
    if (s == "attack" || "a") {
        return ATTACK;
    }
    if (s == "talk" || "c") {
        return CHECK;
    }
    if (s == "inventory" || "i") {
        return INVENTORY;
    }
    if (s == "use" || "u") {
        return USE;
    }
    if (s == "pick" || "p") {
        return PICK;
    }
    if (s == "help" || "h") {
        return HELP;
    }
    return NOTREGISTERED;
}

void InputProcessor::Check(Scene* s, string target)
{
    Checkeable* c = s->IfContains(target);
    if (c->GetName() == "Nothing") {
        cout << "There's no '" + target +"' here that you're looking for." << endl;
    }
    
}

