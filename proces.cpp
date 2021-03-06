#include "proces.h"

void process::swap_elements(int first, int second, std::vector<int> &front, std::vector<int> &middle,
	std::vector<int> &end)
{
	int tmp;

	tmp = front[first];
	front[first] = front[second];
	front[second] = tmp;

	tmp = middle[first];
	middle[first] = middle[second];
	middle[second] = tmp;

	tmp = end[first];
	end[first] = end[second];
	end[second] = tmp;

	tmp = order[first];
	order[first] = order[second];
	order[second] = tmp;
}

process::process(std::string name)
{
	std::ifstream infile(name.c_str());
	if (infile.is_open()) std::cout << "wszystko dobrze" << std::endl;
	else {
		std::cout << "Cos jest zle\n";
		exit(69);
	}
	infile >> size_of_process;
	//size_of_process--;

	std::cout << "\nInicjalizacja\nRozmiar procesu: " << return_size_of_process() << std::endl;
	
	front_time = new std::vector<int>;
	middle_time = new std::vector<int>;
	end_time = new std::vector<int>;
	int tmp;
	
	for (int j = 0; j < size_of_process; j++)
	{
		infile >> tmp;
		front_time->push_back(tmp);
		infile >> tmp;
		middle_time->push_back(tmp);
		infile >> tmp;
		end_time->push_back(tmp);
	}
	
	order = new int[size_of_process];
	for (int i = 0; i < size_of_process; i++)
	{
		order[i] = i;
	}
}

int process::calculate_length_of_process() const {
	int m = 0, i = 0, j = 0, c = 0;
	for (j = 0; j < size_of_process; j++)
	{
		i = order[j];
		m = std::max(m, return_front_time(i)) + return_middle_time(i);
		c = std::max(m + return_end_time(i), c);
	}
	return c;
}



// algorytm jest taki: naprzemiennie wybieram elementy z najkrotszym przygotowaniem,
//a pozniej z najkrotszym stygnieciem i tak je ukladam
void process::sort_process_first() {
	std::vector<int> tmp_front(*front_time);//dzialamy na kopiach, zmieniamy tylko pole order
	std::vector<int> tmp_middle(*middle_time);
	std::vector<int> tmp_end(*end_time);

	std::cout << "Rozmiar procesu: " << return_size_of_process() << std::endl;
	int tmp;


	int at, ends_counter = 0, tmp_swap;
	int is_odd = size_of_process % 2;
	
	
	for (int it = 0; it < size_of_process - it; it++)
	{
		std::cout << "\nKrok: " << it << std::endl;
		
		int smallest_front = it;//tutaj zaczynamy od elementu i-tego
		for (at = it; at<size_of_process - it; at++)
		{
			if (tmp_front[smallest_front] > tmp_front[at])
			{
				smallest_front = at;//jesli jest wiekszy to zapamietujemy ktory to jest
				//std::cout << std::endl << "Najmniejszy przod to: " << tmp_front[smallest_front] << std::endl;
				//std::cout << "Jest na pozycji: " << smallest_front << std::endl;
			}
		}

		//std::cout << "Zamieniam front\n Na pozycji it jest: " << tmp_front[it] << std::endl;
		//std::cout << "Na pozycji smallest_front jest: " << tmp_front[smallest_front] << std::endl;

		swap_elements(smallest_front, it, tmp_front, tmp_middle, tmp_end);
		
		int smallest_end = it+1;
		for (at = smallest_end; at < size_of_process - it; at++)//-ends_counter bo nie ruszamy elementow z konca
		{
			if (tmp_end[smallest_end] > tmp_end[at])
			{
				smallest_end = at;
				//std::cout << std::endl << "Najmniejszy tyl to: " << tmp_end[smallest_end] << std::endl;
				//std::cout << "Jest na pozycji: " << smallest_end << std::endl;
			}
		}

		//std::cout << "Zamieniam end\n Na pozycji size_of_process-it-1 jest: " << tmp_end[size_of_process - it - 1] << std::endl;
		//std::cout << "Na pozycji smallest_end jest: " << tmp_end[smallest_end] << std::endl;

		swap_elements(smallest_end, size_of_process - it - 1, tmp_front, tmp_middle, tmp_end);
				
	}
}

void process::print_order() const
{
	std::cout << "Drukuje kolejnosc: " << std::endl;
	for(int i = 0; i < return_size_of_process(); i++)
	{
		std::cout << order[i]+1 << " ";
	}
}
