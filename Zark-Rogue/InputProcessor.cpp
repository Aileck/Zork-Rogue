#include "InputProcessor.h"

bool InputProcessor::ProcessInput(string input, Scene* scene)
{
    {
        //Split user token to two parts, action + target
        stringstream ss(input);
        string word;
        vector<std::string> words;
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

        std::cout << "Your action: " << action << std::endl;
        std::cout << "Your target: " << target << std::endl;

        return true;
    }
}
