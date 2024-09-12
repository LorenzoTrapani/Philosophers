# Introduction

The Philosophers project is part of the 42 curriculum and is based on the famous dining philosophers problem. This problem illustrates challenges in concurrent programming, where multiple processes must share resources without causing deadlocks or resource starvation.

# Objectives

The main objective of this project is to solve synchronization issues in a multithreaded environment. You will simulate the behavior of philosophers who alternate between thinking, eating, and sleeping, while avoiding situations like deadlocks.

# Problem Overview

In the dining philosophers problem, several philosophers are seated around a circular table. Each philosopher can either be thinking or eating. The number of forks is the same of the philosophers, however each one of them needs two forks to eat.

Key Challenges:

  - Concurrency Management: Ensure proper synchronization between philosophers without causing race conditions.
  - Avoiding Deadlock: Prevent the philosophers from being stuck in a situation where none can proceed.
  - Resource Sharing: Control access to shared resources (forks) using mutexes.

Project Requirements:

  - The program must create a number of philosophers and simulate their behavior.
  - Each philosopher should act independently in a loop of thinking, picking up forks, eating, and sleeping.
  - Philosophers must not starve: they should always get a chance to eat.
  - Implement proper handling of shared resources to avoid conflicts.
  - The program should end cleanly, ensuring all resources are freed.
