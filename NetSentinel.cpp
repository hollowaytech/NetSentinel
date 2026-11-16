// @hollowaytech on GitHub

/* This program is a cybersecurity script that blacklists/blocks IPs using a "firewall".
IPs are blocked based off of maximum attempts. Max attempts variable can be modified and found in the main function.
Default attempt limit is 20 */

// libraries included
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

// function for filling IP array
int fillIPs(string ips[], const int CAPACITY) {
	int count = 0;
	string input;
	while (count < CAPACITY && cin >> input) {
		if (input == "DONE") {
			return count;
		}
		ips[count] = input;
		count++;
	}
	cout << "ERROR. CAPACITY EXCEEDED.";
	exit(1);
}

// function for filling attempts array
void fillattempts(int attempts[], string ips[], int count) {
	for (int i = 0; i < count; i++) {
		cout << "Enter attempts for IP " << ips[i] << ": ";
		int atts;
		cin >> atts;
		attempts[i] = atts;
	}
}

// function for filling success array
void fillsuccess(bool success[], string ips[], int count) {
	for (int i = 0; i < count; i++) {
		cout << "Enter success status for IP " << ips[i] << ": ";
		bool stat;
		cin >> boolalpha >> stat;
		success[i] = stat;
	}
}

// function for printing statistics chart
void printchart(bool success[], int attempts[], string ips[], int count) {
	cout << "| CHART |" << endl;
	for (int i = 0; i < count; i++) {
		cout << "| IP: " << left << setw(15) << ips[i] << " | Attempts: " << setw(4) << attempts[i] << " | Login Success: " << boolalpha << setw(5) << success[i] << " |" << endl;
	}
}

// function for blacklisting IPs
int blacklist_active(int attempts[], string ips[], string blacklist[], int count, int attempt_limit) {
	int blacklist_counter = 0;
	for (int i = 0; i < count; i++) {
		if (attempts[i] > attempt_limit) {
			blacklist[blacklist_counter] = ips[i];
			blacklist_counter++;
		}
	}
	return blacklist_counter;
}

int main() {
	cout << "======NET==SENTINEL======" << endl;
	cout << "| IP blacklister script |" << endl;
	cout << "=========================" << endl << endl;

	// max capacity (100), attempt limit (20) & password for script (hacker)
	const int CAPACITY = 100;
	int attempt_limit = 20;
	string password = "hacker";

	// declarations for arrays
	string ips[CAPACITY];
	int attempts[CAPACITY];
	bool success[CAPACITY];
	string blacklist[CAPACITY];

	// prompt for entering IPs
	cout << "Enter ips here and type 'DONE' to quit: ";
	// IP function called
	int count = fillIPs(ips, CAPACITY);
	cout << endl;

	// attempts function called
	fillattempts(attempts, ips, count);
	cout << endl;

	// success function called
	fillsuccess(success, ips, count);
	cout << endl;

	// chart function called
	printchart(success, attempts, ips, count);
	cout << endl;

	// decision for running blacklist script
	cout << "Run blacklist script? (y/n): ";
	string yorn;
	cin >> yorn;
	cout << endl;

	// if script is ran
	if (yorn == "y") {
		int pass_counter = 0;
		cout << "Enter password for execution: ";
		string pass;
		cin >> pass;
		cout << endl;

		while (pass != password) {
			pass_counter++;
			if (pass_counter > 10) {
				cout << endl;
				cout << "Access to script denied. Exiting program...";
				exit(0);
			}
			cout << "Access denied. Enter password again: ";
			cin >> pass;
		}

		int blacklist_counter = blacklist_active(attempts, ips, blacklist, count, attempt_limit);
		cout << "=======NET===SENTINEL=======" << endl;
		cout << "| SCRIPT CALLED TO EXECUTE |" << endl;
		cout << "============================" << endl << endl;
		cout << "Script working";

		for (int i = 0; i < 5; i++) {
			cout << ".";
			this_thread::sleep_for(chrono::milliseconds(500));
		}
		cout << endl << endl;

		// if no malicious IPs detected
		if (blacklist_counter == 0) {
			cout << "=======================================================" << endl;
			cout << "| NetSentinel did not blacklist any IPs at this time. |" << endl;
			cout << "=======================================================";
		}
		// if malicious IPs are detected
		else {
			cout << "======NET===SENTINEL======" << endl;
			cout << "| MALICIOUS IPS DETECTED |" << endl;
			cout << "==========================" << endl << endl;
			cout << "===================" << endl;
			cout << "| BLACKLISTED IPS |" << endl;
			cout << "-------------------" << endl;
			for (int i = 0; i < blacklist_counter; i++) {
				cout << "| " << left << setw(15) << blacklist[i] << " |" << endl;
			}
			cout << "===================" << endl << endl;
			cout << "=======NET===SENTINEL=======" << endl;
			cout << "| IPS BLOCKED SUCCESSFULLY |" << endl;
			cout << "============================";
		}
	}
	// if script is not ran
	else {
		cout << "Okay, program exiting...";
	}

	return 0;
}