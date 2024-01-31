#include <iostream>
#include <bitset> // This header of the bitset uses the bitset class to store bits
#include <iomanip>

using namespace std;

int main() {
    // Create the bit string
    bitset<32> my_bit_string(0b11011101100111000001100010110101);
    // Create the bit mask
    bitset<32> my_bit_mask(0b00000000000010101111000000000000);
    // Create storage to hold the result of bit masking
    bitset<32> result;

    // Print the bit string in hexadecimal and binary
    cout << "0x" << setw(8) << setfill('0')
         << hex << uppercase << my_bit_string.to_ulong()
         << "     " << my_bit_string << endl;

    // Print the bit mask in hexadecimal and binary and the operation
    cout << "0x" << setw(8) << setfill('0') << hex
         << uppercase << my_bit_mask.to_ulong() << "     "
         << my_bit_mask << "  & " << endl;

    // Print the operation seperation line
    cout << "              --------------------------------------"
         << endl;

    // Calculate and assign the result
    result = my_bit_string & my_bit_mask;

    // Print the result to the screen
    cout << "0x" << setw(8) << setfill('0') << hex
         << uppercase << result.to_ulong() << "     "
         << result << endl;

    return 0;
}
