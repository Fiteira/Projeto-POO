#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;


xml_document<> doc;
xml_node<> * root_node = NULL;

int main(void)
{
    cout << "\nParsing my students data (sample.xml)....." << endl;

    // Read the sample.xml file
    ifstream theFile ("sample.xml");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer
    doc.parse<0>(&buffer[0]);

    // Find out the root node
    root_node = doc.first_node("DADOS");

    // Iterate over the student nodes
    for (xml_node<> * definicoes_no = root_node->first_node("DEFINICOES"); definicoes_no; definicoes_no = definicoes_no->next_sibling())
    {

            // Interate over the Student Names
        for(xml_node<> * nome_no = definicoes_no->first_node("NOME"); nome_no; nome_no = nome_no->next_sibling())
        {
            cout << " =   " << nome_no->value();
            cout << endl;
        }
       /* for(xml_node<> * idade_no = definicoes_no->first_node("IDADE"); idade_no; idade_no = idade_no->next_sibling())
        {
            cout << "Idade =   " << idade_no->value();
            cout << endl;
        }
        cout << endl;
 */
    }


    return 0;
}
