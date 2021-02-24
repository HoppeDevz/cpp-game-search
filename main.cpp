#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// functions declaration //
void RenderHomePage();


void ClearScreen() {
    cout << string( 100, '\n' );
}

void showDataBase() {
    int id;
    int registers_searched = 0;

    std::string name;
    std::string platform;
    std::string desc;
    
    std::string line_;
    ifstream file("db.txt");

    if (file.is_open()) {

        while (getline(file, line_)) {
            
            cout<<line_<<"\n";
            registers_searched = registers_searched + 1;
        }

        file.close();
    }


    std::string action;

    while (true) {
        cout<<"\n \n";
        cout<<"Registros Encontrados: " << registers_searched << "\n";
        cout<<"Digite VOLTAR: ";
        cin>>action;

        if (action == "VOLTAR") {
            ClearScreen();
            RenderHomePage();
            break;
        }
    }
}

void SearchRegisterFromId() {
    int target_id;
    int registers_searched = 0;

    int id;
    int age;
    std::string name;
    std::string platform;
    std::string desc;
    
    std::string line_;
    ifstream file;
    file.open("db.txt");

    cout << "Digite o ID do jogo: ";
    cin >> target_id;

    ClearScreen();

    cout << "Resultados para o ID:" << target_id << "\n \n";

    if (file.is_open()) {

        while (file >> id >> name >> age >> platform >> desc) {

            if (id == target_id) {
                cout << id << " " << name << " " << age << " " << platform << " " << desc;

                registers_searched = registers_searched + 1;
            }

        }

        file.close();

    }
    

    std::string action;

    while (true) {
        cout<<"\n \n";
        cout<<"Registros Encontrados: " << registers_searched << "\n";
        cout<<"Digite VOLTAR ou BUSCAR \n";
        cin>>action;

        if (action == "BUSCAR") {
            ClearScreen();
            SearchRegisterFromId();
            break;
        }

        if (action == "VOLTAR") {
            ClearScreen();
            RenderHomePage();
        }
    }
}

void SearchRegisterFromGameName() {
    std::string target_name;
    int registers_searched = 0;

    int id;
    int age;
    std::string name;
    std::string platform;
    std::string desc;
    
    std::string line_;
    ifstream file;

    file.open("db.txt");

    cout << "Digite o nome do jogo: ";
    cin >> target_name;

    ClearScreen();

    cout << "Resultados para o nome:" << target_name << "\n \n";

    if (file.is_open()) {

        while (file >> id >> name >> age >> platform >> desc) {

            if (name == target_name) {
                cout << id << " " << name << " " << age << " " << platform << " " << desc << "\n";

                registers_searched = registers_searched + 1;
            }

        }

        file.close();

    }
    

    std::string action;

    while (true) {
        cout<<"\n \n";
        cout<<"Registros Encontrados: " << registers_searched << "\n";
        cout<<"Digite VOLTAR ou BUSCAR \n";
        cin>>action;

        if (action == "BUSCAR") {
            ClearScreen();
            SearchRegisterFromGameName();
            break;
        }

        if (action == "VOLTAR") {
            ClearScreen();
            RenderHomePage();
        }
    }
}

void SearchRegisterFromYear() {
    int target_year;
    int registers_searched = 0;

    int id;
    int age;
    std::string name;
    std::string platform;
    std::string desc;
    
    std::string line_;
    ifstream file("db.txt");

    cout << "Digite o ano do jogo: ";
    cin >> target_year;

    ClearScreen();

    cout << "Resultados para o ano de lancamento:" << target_year << "\n \n";

    if (file.is_open()) {

        while (file >> id >> name >> age >> platform >> desc) {

            if (age == target_year) {
                cout << id << " " << name << " " << age << " " << platform << " " << desc << "\n";

                registers_searched = registers_searched + 1;
            }

        }

        file.close();

    }
    

    std::string action;

    while (true) {
        cout<<"\n \n";
        cout<<"Registros Encontrados: " << registers_searched << "\n";
        cout<<"Digite VOLTAR ou BUSCAR \n";
        cin>>action;

        if (action == "BUSCAR") {
            ClearScreen();
            SearchRegisterFromGameName();
            break;
        }

        if (action == "VOLTAR") {
            ClearScreen();
            RenderHomePage();
        }
    }
}

void SearchRegisterFromPlatform() {
    std::string target_platform;
    int registers_searched = 0;

    int id;
    int age;
    std::string name;
    std::string platform;
    std::string desc;
    
    std::string line_;
    ifstream file("db.txt");

    cout << "Digite a plataforma do jogo: ";
    cin >> target_platform;

    ClearScreen();

    cout << "Resultados para a plataforma:" << target_platform << "\n \n";

    if (file.is_open()) {

        while (file >> id >> name >> age >> platform >> desc) {

            if (platform == target_platform) {
                cout << id << " " << name << " " << age << " " << platform << " " << desc << "\n";

                registers_searched = registers_searched + 1;
            }

        }

        file.close();

    }
    

    std::string action;

    while (true) {
        cout<<"\n \n";
        cout<<"Registros Encontrados: " << registers_searched << "\n";
        cout<<"Digite VOLTAR ou BUSCAR \n";
        cin>>action;

        if (action == "BUSCAR") {
            ClearScreen();
            SearchRegisterFromGameName();
            break;
        }

        if (action == "VOLTAR") {
            ClearScreen();
            RenderHomePage();
        }
    }
}

int CalculateAutoIncrementId() {
    int id = 1;

    std::string line_;
    ifstream file("db.txt");

    if (file.is_open()) {

        while (getline(file, line_)) {
            
            cout<<line_<<"\n";
            id = id + 1;
        }

        file.close();
    }

    return id;
}

void RegisterGameInDatabase() {
    ClearScreen();

    std::string line_;
    ifstream file;
    file.open("db.txt");

    ofstream arquivo;
    arquivo.open("db.txt", ios::app);

    int id = CalculateAutoIncrementId();
    std::string age;
    std::string name;
    std::string platform;
    std::string desc;

    cout << "\n \n";

    cout << "Digite o nome do jogo: ";
    cin >> name;

    cout << "Digite o ano de lancamento do jogo: ";
    cin >> age;

    cout << "Digite a plataforma do jogo";
    cin >> platform;

    cout << "Digite a descrição do jogo: ";
    cin >> desc;

    if (file.is_open()) {

        arquivo << id << " " << name << " " << age << " " << platform << " " << desc << "\n";

        arquivo.close();
        file.close();
    }

    cout<< "\n\n";
    cout<< "Jogo cadastrado com sucesso! \n";

    std::string action;
    cout<< "Digite VOLTAR ou CADASTRAR \n";

    cin>>action;

    if (action == "VOLTAR") {
        ClearScreen();
        RenderHomePage();
    }

    if (action == "CADASTRAR") {
        ClearScreen();
        RegisterGameInDatabase();
    }
}

int GetDataBaseLength() {
    int length = 0;

    std::string line_;

    ifstream file;
    file.open("db.txt");

    if (file.is_open()) {   
        
        while (getline(file, line_)) {

            length = length + 1;
            
        }

        file.close();
    }

    return length;
}

void RemoveGameFromDatabase() {
    ClearScreen();

    int db_length = GetDataBaseLength();

    bool exist_id = false;

    int target_id;
    int line_id = 0;

    int id;
    std::string name;
    std::string age;
    std::string platform;
    std::string desc;

    cout << "Digite o ID que deseja remover: ";
    cin >> target_id;

    std::string line_;
    
    ifstream file;
    file.open("db.txt");

    std::string lines[db_length - 1];

    if (file.is_open()) {   
        
        while (file >> id >> name >> age >> platform >> desc) {
            
            if (id != target_id) {
                lines[line_id] = to_string(id) +  " " + name + " " + age + " " + platform + " " + desc + "\n";
                line_id = line_id + 1;
            }
            
        }

        file.close();
    }

    int index = 0;
    ofstream arq;
    arq.open("db.txt");

    if (arq.is_open()) {

        while ( index < db_length - 1 ) {
            arq << lines[index];
            cout << lines[index];
            index = index + 1;
        }

        arq.close();
    }

    cout << "Registro com ID " << target_id << " removido com sucesso!";

    int w;
    cin >> w;
}

void RenderHomePage() {
    ClearScreen();

    int option;

    cout << " #####     #    #     # #######     #####  #######    #    ######   #####  #     # \n #     #   # #   ##   ## #          #     # #         # #   #     # #     # #     # \n #        #   #  # # # # #          #       #        #   #  #     # #       #     # \n #  #### #     # #  #  # #####       #####  #####   #     # ######  #       ####### \n #     # ####### #     # #                # #       ####### #   #   #       #     # \n #     # #     # #     # #          #     # #       #     # #    #  #     # #     # \n #####  #     # #     # #######     #####  ####### #     # #     #  #####  #     # \n \n";

    /*
       █████████    █████████   ██████   ██████ ██████████     █████████  ██████████   █████████   ███████████     █████████  █████   █████ 
      ███░░░░░███  ███░░░░░███ ░░██████ ██████ ░░███░░░░░█    ███░░░░░███░░███░░░░░█  ███░░░░░███ ░░███░░░░░███   ███░░░░░███░░███   ░░███  
     ███     ░░░  ░███    ░███  ░███░█████░███  ░███  █ ░    ░███    ░░░  ░███  █ ░  ░███    ░███  ░███    ░███  ███     ░░░  ░███    ░███ 
    ░███          ░███████████  ░███░░███ ░███  ░██████      ░░█████████  ░██████    ░███████████  ░██████████  ░███          ░███████████ 
    ░███    █████ ░███░░░░░███  ░███ ░░░  ░███  ░███░░█       ░░░░░░░░███ ░███░░█    ░███░░░░░███  ░███░░░░░███ ░███          ░███░░░░░███ 
    ░░███  ░░███  ░███    ░███  ░███      ░███  ░███ ░   █    ███    ░███ ░███ ░   █ ░███    ░███  ░███    ░███ ░░███     ███ ░███    ░███ 
     ░░█████████  █████   █████ █████     █████ ██████████   ░░█████████  ██████████ █████   █████ █████   █████ ░░█████████  █████   █████
      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░     ░░░░░ ░░░░░░░░░░     ░░░░░░░░░  ░░░░░░░░░░ ░░░░░   ░░░░░ ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░ 
    */

    cout<< "Selecione uma opcao: \n \n";

    cout<< "1 - Mostrar banco de dados \n";
    cout<< "2 - Procurar Cadastro(s) por ID \n";
    cout<< "3 - Procurar Cadastro(s) por nome \n";
    cout<< "4 - Procurar Cadastro(s) por ano de lancamento \n";
    cout<< "5 - Procurar Cadastro(s) por plataforma \n";
    cout<< "6 - Cadastrar um jogo no banco de dados \n";
    cout<< "7 - Remover um jogo no banco de dados \n";

    cin>>option;

    if (option == 1) {
        ClearScreen();
        showDataBase();
    }

    if (option == 2) {
        ClearScreen();
        SearchRegisterFromId();
    } 

    if (option == 3) {
        ClearScreen();
        SearchRegisterFromGameName();
    }

    if (option == 4) {
        ClearScreen();
        SearchRegisterFromYear();
    }

    if (option == 5) {
        ClearScreen();
        SearchRegisterFromPlatform();
    }

    if (option == 6) {
        ClearScreen();
        RegisterGameInDatabase();
    }

    if (option == 7) {
        ClearScreen();
        RemoveGameFromDatabase();
    }

    
}

int main() {
    RenderHomePage();

    return 0;
}
