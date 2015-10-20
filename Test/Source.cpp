#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void main() {

	//given a list of jobs
	struct job {
		double time; 
		double weight; 
		int jobNumber; //store what number job it is, as the sorting will mix the jobs around
		double greedyCriteria; //stores the ratio of weight and time
		bool operator<(const job& test) const { return greedyCriteria > test.greedyCriteria; }
		/*This operator provides the sort algorithm a means of comparing each job
		  As the algorithm only uses '<' and not '>', it is only necessary to define this one */
	};

	vector<job> jobList;

	//ask user to fill in information on jobs
	int numOfJobs;
	cout << "Hello! How many jobs will you process today?" << endl;
	cin >> numOfJobs;
	for (int x = 0; x < numOfJobs; x++) {
		job newJob;
		cout << "What is the time for job number " << x + 1 << "?" << endl;
		cin >> newJob.time;
		cout << "What is the weight for job number " << x + 1 << "?" << endl;
		cin >> newJob.weight;
		newJob.jobNumber = x + 1;
		newJob.greedyCriteria = newJob.weight / newJob.time;

		jobList.push_back(newJob);
	}


	//GOAL:: assign a starting time S to each job
	//Minimize sum >= i >= Wi*(Si+Ti)
	//Greedy Algorithm: Sort the jobs by the ratio weight/time
	sort(jobList.begin(), jobList.end()); //sorts the jobs by the .greedyCriteria stored in each
	double timeelapsed=0;
	double solution=0;

	cout << "The optimal solution is:" << endl;
	for (int i = 0; i < jobList.size(); i++) {
		cout << "Job number " << jobList[i].jobNumber << endl;
		solution += jobList[i].weight * (jobList[i].time + timeelapsed);
		timeelapsed += jobList[i].time;
	}
	cout << "The solution value comes to " << solution << endl;

	system("Pause");
	return;
}