#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void main() {

	//given a list of jobs
	//each job has T time and W weight
	struct job {
		int time;
		int weight;
		int jobNumber;
		int greedyCriteria;
		bool operator<(const job& rhs) const { return greedyCriteria < rhs.greedyCriteria; }
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

	sort(jobList.begin(), jobList.end());

	cout << "The optimal solution is:" << endl;
	for (int i = 0; i < jobList.size(); i++) {
		cout << "Job number " << jobList[i].jobNumber << endl;
	}
	
	system("Pause");
	return;
}