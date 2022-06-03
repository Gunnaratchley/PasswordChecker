#include <fstream>
#include <iostream>
#include <string>

const size_t minimum_password_length = 8;

int main()
{
	std::ifstream fin;
	fin.open("passwords1.txt");
	if (fin)
	{
		while (!fin.eof())
		{
			std::string password;
			getline(fin, password);
			auto is_password_valid = true;	
			if (password.size() < minimum_password_length)
			{
			
				auto is_password_valid = false;
				if (is_password_valid == false)
				{
					std::ofstream fout;
					fout.open("invalid_passwords.txt");
					fout << password << std::endl;
				}
			} //else, password is valid for now, do_nothing();

			auto special_character = false;	
			for (char c : password)
			{
				if (ispunct(c))
				{
					//std::cout << "Password cannot contain a special character";
					auto special_character = true;
					auto is_password_valid = false;
					if (is_password_valid == false)
					{
						std::ofstream fout;
						fout.open("invalid_passwords.txt");
						fout << password << std::endl;
					}
				} //else, password is valid for now, do_nothing();
			}

			auto digit_count = 0;
			for (auto index = 0; index < password.size(); index++)
			{
				if (isdigit(password[index]))
				{
					digit_count++;
				
				}
				else
				{
					auto is_password_valid = false;
					if (is_password_valid == false)
					{
						std::ofstream fout;
						fout.open("invalid_passwords.txt");
						fout << password << std::endl;

						fout.close();
					}
				}
			}
			if (digit_count < 2)
			{
				auto is_password_valid = false;
			} // else, password is vaid, do_nothing();

			if (is_password_valid == true)
			{
				std::ofstream fout;
				fout.open("valid_passwords.txt");
				fout << password << std::endl;

				fout.close();
			}
			
		}

		fin.close();
	}
	return 0;
 }