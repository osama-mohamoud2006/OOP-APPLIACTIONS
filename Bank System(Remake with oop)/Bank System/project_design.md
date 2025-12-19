# Project Design Documentation

## Class Diagram

The following class diagram illustrates the relationships between the core classes, UI screens, and utility dependencies in the Bank System.

```mermaid
classDiagram
    class clsPerson {
        #string _FirstName
        #string _LastName
        #string _Email
        #string _Phone
        +string FullName()
        +Print()
    }

    class clsBankClient {
        -string _AccountNumber
        -string _Pin
        -double _Balance
        -bool _MarkForDelete
        +Find(AccountNumber)
        +Save()
        +DeleteClient()
        +static IsClientExist()
        +static GetAllClientsInVector()
        +static GetTotalBalances()
    }

    class clsScreen {
        #_ShowScreenHeader(Title, SubTitle)
        #_PrintMenuOption(Title, SubTitle)
        -static _PrintCentered(Text)
        -static _GetSystemDate()
    }

    class clsMainMenuScreen {
        -_EMainMenu()
        -_ShowListClient()
        -_ShowAddNewClientScreen()
        -_ShowDeleteClientScreen()
        -_ShowUpdateClientScreen()
        -_ShowFindClientScreen()
        -_ShowTransactionsScreen()
        -_ShowAdminScreen()
        -_ShowLogoutScreen()
        +_ShowMainMenuScreen()
        -_PerformMainMenuOption()
    }

    class clsInputAndValidation {
        <<Utility>>
        +read_string()
        +enter_number_from_to()
    }

    %% Inheritance Relationships
    clsPerson <|-- clsBankClient : Inherits
    clsScreen <|-- clsMainMenuScreen : Inherits

    %% Dependencies
    clsMainMenuScreen ..> clsBankClient : Manages
    clsMainMenuScreen ..> clsInputAndValidation : Uses
    clsBankClient ..> clsString : Uses (String Manipulation)
```

## System Flow Chart

The following flow chart demonstrates the main execution loop of the application, starting from the entry point in `Main.cpp` and navigating through the Main Menu options.

```mermaid
flowchart TD
    Start([Start Program]) --> Main[Main.cpp]
    Main --> ShowMainMenu[clsMainMenuScreen::_ShowMainMenuScreen]
    
    subgraph MainMenuLoop [Main Menu Loop]
        ShowHeader[Show Header & Date]
        ShowOptions[Display Menu Options 1-9]
        Input[Get User Input]
        
        ShowHeader --> ShowOptions --> Input
        
        Input -- 1 --> ListClients[List Clients Screen]
        Input -- 2 --> AddClient[Add New Client Screen]
        Input -- 3 --> DeleteClient[Delete Client Screen]
        Input -- 4 --> UpdateClient[Update Client Screen]
        Input -- 5 --> FindClient[Find Client Screen]
        Input -- 6 --> Transactions[Transactions Menu Screen]
        Input -- 7 --> Admin[Admin Menu Screen]
        Input -- 8 --> Logout[Logout Screen]
        Input -- 9 --> ExitApp[Exit System]
        
        ListClients --> Pause1[Wait for Input] --> ShowHeader
        AddClient --> Pause2[Wait for Input] --> ShowHeader
        DeleteClient --> Pause3[Wait for Input] --> ShowHeader
        UpdateClient --> Pause4[Wait for Input] --> ShowHeader
        FindClient --> Pause5[Wait for Input] --> ShowHeader
        Transactions --> Pause6[Wait for Input] --> ShowHeader
        Admin --> Pause7[Wait for Input] --> ShowHeader
        Logout --> ShowHeader
    end

    ExitApp --> End([End Program])
```
