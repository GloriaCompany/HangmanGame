#include "DesignHangman.h"

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
	std::cout << 1;
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
	std::cout << 2;
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
	std::cout << 3;
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
	std::cout << 4;
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
	std::cout << 5;
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
	std::cout << 6;
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
	std::cout << 7;
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
	std::cout << 8;
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