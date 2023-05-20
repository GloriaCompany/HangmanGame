#include "DesignHangman.h"
#include "DesignDefine.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>

void DesignHangman::HangmanStageStart() {
   
    std::wcout
        << DGR << L"      ╭──\n" << WHT
        << DGR << L"      │╱\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageOne() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageTwo() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageThree() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │  " << YEL << L"        O\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageFour() {

    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │  " << YEL << L"        O\n"
        << DGR << L"      │  " << GRN << L"        │\n"
        << DGR << L"      │  " << GRN << L"        │\n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageFive() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │  " << YEL << L"        O\n"
        << DGR << L"      │  " << RED << L"       ╱" << GRN << L"│\n"
        << DGR << L"      │  " << GRN << L"        │ \n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageSix() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │  " << YEL << L"        O\n"
        << DGR << L"      │  " << RED << L"       ╱" << GRN << L"│" << MAG << L"╲ \n"
        << DGR << L"      │  " << GRN << L"        │ \n"
        << DGR << L"      │\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageSeven() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │  " << YEL << L"        O\n"
        << DGR << L"      │  " << RED << L"       ╱" << GRN << L"│" << MAG << L"╲ \n"
        << DGR << L"      │  " << GRN << L"        │ \n"
        << DGR << L"      │  " << BLU << L"       ╱\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}

void DesignHangman::HangmanStageEight() {
    
    std::wcout
        << DGR << L"      ╭──────────┬───\n" << WHT
        << DGR << L"      │╱ " << WHT << L"        ┆\n"
        << DGR << L"      │  " << WHT << L"        ┆\n"
        << DGR << L"      │  " << YEL << L"        O\n"
        << DGR << L"      │  " << RED << L"       ╱" << GRN << L"│" << MAG << L"╲ \n"
        << DGR << L"      │  " << GRN << L"        │ \n"
        << DGR << L"      │  " << BLU << L"       ╱" << CYN << L" ╲\n"
        << DGR << L"      │\n"
        << L"      │\n"
        << L"      │\n"
        << L"    ══╧══════════════\n" << WHT;
}