#include "Window.h"                    //            The header file of the form
using namespace CraneTranformation;    //            The name of the namespace in CraneWindow.h
[STAThreadAttribute]                   //            Run this program in STA mode
int main(){
	CraneWindow fm;                    //            The form to be created and shown
	fm.ShowDialog();                   //            Show the form
	return 0;
}