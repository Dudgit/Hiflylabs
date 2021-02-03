#include "cuda_utility.cuh"

int main()
{
	
	int number_of_steps = 1000;
	//Initialize data holder vectors
	std::vector<bool> reff_vec(h * w);
	std::vector<float> gpu_vec(h * w);

	//Creating a random number generator
	std::random_device rd{};
	std::mt19937 mersenne_engine{ rd() };
	std::uniform_real_distribution<float> dist{ 0, 100 };
	auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine) < 50 ? false : true; };
	
	//Fill values of the 2 vector
	generate(reff_vec.begin(), reff_vec.end(), gen);
	std::copy(reff_vec.begin(), reff_vec.end(), gpu_vec.begin());
	
	//Creating the table object
	table t1(h, w, reff_vec);


	//Creating arrays for host and device
	float* host_array = gpu_vec.data();
	float* device_output;
	cudaMalloc(&device_output, w * h * sizeof(float));

	//Output data
	std::ofstream handler_naive("data/naive_conway.txt");
	std::ofstream handler_gpu("data/texture_conway.txt");

	//Write out, the initial table
	write_out_result(host_array, handler_gpu);
	t1.write_table_out(handler_naive);

	//Executing the simulation
	for (int i = 0; i < number_of_steps; ++i)
	{
		//Creating the cuda texture object
		auto texObj = get_texobject(host_array);
		
		// One step 
		step(host_array,device_output);
		t1.do_game();

		//Write out results
		write_out_result(host_array, handler_gpu);
		t1.write_table_out(handler_naive);
	}

	
	//Free the allocated memory
	auto err = cudaFree(device_output);
	if (err != cudaSuccess) { std::cout << "Error freeing array allocation: " << cudaGetErrorString(err) << "\n"; return -1; }
	
	handler_gpu.close();
	handler_naive.close();

}