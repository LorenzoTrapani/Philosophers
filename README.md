The philo project is an essential part of the 42 curriculum. It tasks students with creating a simulation of the dining philosophers problem using threads and mutexes. This project aims to improve understanding of concurrency, synchronization, and efficient coding practices in C.

OBJECTIVE:
- Simulate Philosophers' Dining: Implement a simulation where philosophers alternately eat, think, and sleep, using shared resources (forks).
- Thread Management: Create threads for each philosopher and ensure proper synchronization to avoid race conditions.
- Mutex Usage: Use mutexes to manage access to shared resources (forks) and prevent data races.
- Monitor Philosopher State: Use an external thread to monitor the state of philosophers and ensure they don't starve.
- Error Handling: Ensure thorough error handling to prevent unexpected crashes (segmentation faults, bus errors, etc.).
- Memory Management: Properly manage dynamic memory allocation to avoid memory leaks.

KEY FEATURES:
- Philosopher Threads: Each philosopher is represented by a separate thread.
- Fork Management: Use mutexes to manage access to forks and ensure proper synchronization.
- State Monitoring: An external thread monitors the state of each philosopher to ensure they do not starve.
- Logging State Changes: Log state changes (eating, thinking, sleeping) with timestamps to track the behavior of philosophers.
