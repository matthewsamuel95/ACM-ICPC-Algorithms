  #include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;


class worker
{
public:
    long long int id;
    long long int next_free_time;
    worker(long long int id)
    {
        this->id=id;
        next_free_time=0;
    }
};

struct compare{
    bool operator()(const worker &w1, const worker &w2) const {
		if(w1.next_free_time == w2.next_free_time)
			return w1.id > w2.id;
		else
            return w1.next_free_time > w2.next_free_time;
    }
};

class JobQueue {
 private:
  long long int num_workers_;
  vector<long long int> jobs_;

  vector<long long int> assigned_workers_;
  vector<long long int> start_times_;

  void WriteResponse() const {
    for (long long int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    long long int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(long long int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue <worker, vector<worker>, compare> pq;
    long long int i=0;
    for(i=0;i<num_workers_;i++)
    {
        pq.push(worker(i));
    }

    for (i = 0; i < jobs_.size(); ++i) {
      worker free_thread = pq.top();
      pq.pop();
      assigned_workers_[i] = free_thread.id;
      start_times_[i] = free_thread.next_free_time;
      free_thread.next_free_time += jobs_[i];
      pq.push(free_thread);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};



int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
