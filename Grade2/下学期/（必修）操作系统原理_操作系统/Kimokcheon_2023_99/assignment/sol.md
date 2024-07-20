**List and briefly define the four main elements of a computer.**A processor, which controls the operation of the computer and performs its data processing functions ; a main memory, which stores both data and instructions; I/O modules, which move data between the computer and its external environment; and the system bus, which provides for communication among processors, main memory, and I/O modules.

**In general terms, what are the four distinct actions that a machine instruction can specify?** (1) Processor-memory: Data may be transferred from processor to memory or from memory to processor.  (2) Processor-I/O: Data may be transferred to or from a peripheral device  by transferring between the processor and an I/O module.  (3) Data processing: The processor may perform some arithmetic or logic  operation on data.  (4) Control: An instruction may specify that the  sequence of execution be altered. 

**What is an interrupt?** An interrupt is a mechanism by which other modules (I/O, memory)  may interrupt the normal sequencing of the processor

**How can multiple interrupts be serviced by setting priorities?** Multiple interrupts may be serviced by assigning different priorities to interrupts arising from different sources. This enables a higher-priority interrupt to be serviced first when multiple requests arrive simultaneously; it also allows a higher-priority interrupt to pre-empt a lower-priority interrupt. For example, suppose a system has assigned a higher priority to a communication line and a lower priority to a magnetic disk. When two simultaneous requests arrive, the computer services the communication line. Similarly, if some disk operations are ongoing when a request for the communication line arrives, the state of the disk is put in a stack and the communication line operations are catered to.

**How can multiple interrupts be serviced by setting priorities?** Multiple interrupts may be serviced by assigning different priorities to interrupts arising from different sources. This enables a higher-priority interrupt to be serviced first when multiple requests arrive simultaneously; it also allows a higher-priority interrupt to pre-empt a lower-priority interrupt. For example, suppose a system has assigned a higher priority to a communication line and a lower priority to a magnetic disk. When two simultaneous requests arrive, the computer services the communication line. Similarly, if some disk operations are ongoing when a request for the communication line arrives, the state of the disk is put in a stack and the communication line operations are catered to.

**What characteristics are observed while going up the memory hierarchy?** (1) Increasing cost per bit (2) Decreasing capacity (3) Decreasing access time (4) Increasing frequency of access to the memory by the processor

**What is the difference between a multiprocessor and a multicore system?** A multicore computer is a special case of a multiprocessor, in which all  of the processors are on a single chip.

**What are three objectives of an OS design?** (1) Convenience: OS makes computer more convenient to use (2) Efficiency: OS allows computer system resources to be used in an efficient manner (3) Ability to evolve: OS should be constructed in such a way as to permit effective development, testing, and introduction of new system functions without interfering with service.

**What is the kernel of an OS?** The kernel is a portion of the operating system that includes the most  heavily used portions of software. Generally, the kernel is maintained  permanently in main memory. The kernel runs in a privileged mode and  responds to calls from processes and interrupts from devices. 

**What is multiprogramming?** Multiprogramming is a mode of operation that provides for the  interleaved execution of two or more computer programs by a single  processor. 

**What is a process?** A process is a program in execution. A process is controlled and  scheduled by the operating system. 

**How is the execution context of a process used by the OS?** The execution context, or process state, is the internal data by which the operating system is able to supervise and control the process. This internal information is separated from the process, because the operating system has information not permitted to the process. The context includes all of the information that the operating system needs to manage the process and that the processor needs to execute the process properly. The context includes the contents of the various processor registers, such as the program counter and data registers. It also includes information of use to the operating system, such as the priority of the process and whether the process is waiting for the completion of a particular I/O event.

**List and briefly explain five storage management responsibilities of a typical OS.** Process isolation:The operating system must prevent independent processes from interfering with each other's memory, both data and instructions. Automatic allocation and management: Programs should be dynamically allocated across the memory hierarchy as required. Allocation should be transparent to the programmer. Thus, the programmer is relieved of concerns relating to memory limitations, and the operating system can achieve efficiency by assigning memory to jobs only as needed. Support of modular programming: Programmers should be able to define program modules, and to create, destroy, and alter the size of modules dynamically. Protection and access control: Sharing of memory, at any level of the memory hierarchy, creates the potential for one program to address the memory space of another. This is desirable when sharing is needed by particular applications. At other times, it threatens the integrity of programs and even of the operating system itself. The operating system must allow portions of memory to be accessible in various ways by various users. Long-term storage: Many application programs require means for storing information for extended periods of time, after the computer has been powered down.

**2.7. What is time slicing?** A technique adopted in time-sharing systems to distribute CPU time to multiple users. In this technique, a system clock generates interrupts at a particular rate. At each clock interrupt, the OS regains control and can assign the processor to another user. Thus, at regular time intervals, the current user is preempted and another user is loaded in. To preserve the old user program status for later resumption, the old user programs and data are written out to disk before the new user programs and data are read in. Subsequently, the old user program code and data are restored in main memory when that program is given a turn in a subsequent time-slice.

**2.8. Describe the round-robin scheduling technique.** Round robin is a scheduling algorithm in which processes are activated  in a fixed cyclic order; that is, all processes are in a circular queue. A  process that cannot proceed because it is waiting for some event (e.g.  termination of a child process or an input/output operation) returns  control to the scheduler.

**2.9(old). Explain the difference between a monolithic kernel and a microkernel.** A monolithic kernel is a large kernel containing virtually the complete operating system, including scheduling, file system, device drivers, and memory management. All the functional components of the kernel have access to all of its internal data structures and routines. Typically, a monolithic kernel is implemented as a single process, with all elements sharing the same address space. A microkernel is a small privileged operating system core that provides process scheduling, memory management, and communication services and relies on other processes to perform some of the functions traditionally associated with the operating system kernel.

**2.10. What is multithreading?**Multithreading is a technique in which a process, executing an  application, is divided into threads that can run concurrently. 

**2.11(old). List the key design issues for an SMP(对称多处理) operating system.**Simultaneous concurrent processes or threads; scheduling; synchronization; memory management; reliability and fault tolerance.

**3.1. What is an instruction trace?** An instruction trace for a program is the sequence of instructions that  execute for that process. 

**3.2. Explain the concept of a process and mark its differences from a program.** A process is an instance of a program being executed. A program is a passive entity whereas a process is an active entity.

**3.7. List four characteristics of a suspended process.** (1) The process is not immediately available for execution. (2) The  process may or may not be waiting on an event. If it is, this blocked  condition is independent of the suspend condition, and occurrence of the  blocking event does not enable the process to be executed. (3) The  process was placed in a suspended state by an agent; either itself, a parent process, or the operating system, for the purpose of preventing  its execution. (4) The process may not be removed from this state until  the agent explicitly orders the removal.

**3.9. What are the elements of a process image?** (1) User Program: Comprises the program to be executed (2) User Data: modifiable part of user space. Generally, includes a user stack area, program data, and programs that can be modified (3) Stack: Used to store parameters and calling addresses for procedures and system calls. Each process has one or more LIFO (Last In First Out) stacks associated with (4) Process Control Block: Contains many pieces of information associated with a specific process, like process identifier, process state information, and process control information

**3.11. What are the steps performed by an OS to create a new process?** (1) Assign a unique process identifier to the new process.  (2) Allocate  space for the process.  (3) Initialize the process control block.  (4) Set the appropriate linkages.  (5) Create or expand other data structures.

**3.13. Give three examples of an interrupt.** Clock interrupt, I/O interrupt, memory fault. 

**4.2. List reasons why a mode switch between threads may be cheaper than a mode switch  between processes.**  Less state information is involved. 

**4.3. What are the two separate and potentially independent characteristics embodied in  the concept of process?**  Resource ownership and scheduling/execution. Shared memory. Reduced context switching. Faster synchronization mechanisms.

**4.4. Give four general examples of the use of threads in a single-user multiprocessing  system.** Foreground/background work; asynchronous processing; speedup of  execution by parallel processing of data; modular program structure.

**4.5. How is a thread different from a process?** Process: (1) Generally, more than one process cannot share same memory. Sharing memory among processes requires additional memory-management schemes (2) Process creation, process execution, and process switch are time consuming. (3) Processes are generally loosely coupled and so a lesser amount of resource sharing is possible. (4) Communication between processes is difficult and requires system calls. Thread: (1) Threads of the same process can share the same memory unless they are specially allotted separate memory locations. (2) Thread creation, thread execution, and thread switch are much faster in comparison. (3) As the threads of a process are tightly coupled; a greater amount of resource sharing is possible. (4) Communication between threads is much easier and more efficient.

**4.6. What are the advantages of using multithreading instead of multiple processes?**(1) the costs associated with context switching, communication, data sharing, and synchronisation are lower. (2) On single-processor machines, multithreading is particularly advantageous when the jobs are varied in terms of time and resource requirements and when some jobs require concurrent processing. (3) On multiprocessor systems, multithreading may be able to take advantage of the additional hardware (if OS supports it), thus resulting in better overall performance.

**5.1. List four design issues for which the concept of concurrency is relevant.** Communication among processes, sharing of and competing for  resources, synchronization of the activities of multiple processes, and  allocation of processor time to processes. 

**5.2. What are three contexts in which concurrency arises?** Multiple applications, structured applications, operating-system  structure.

**5.3. What is a race condition?** A race condition occurs when multiple processes or threads read and write data items so that the final outcome depends on the order of execution of instructions in the multiple processes.

**5.4. List three degrees of awareness between processes and briefly define each.** (1) Processes unaware of each other: These are independent processes  that are not intended to work together.  (2) Processes indirectly aware of  each other: These are processes that are not necessarily aware of each  other by their respective process IDs, but that share access to some  object, such as an I/O buffer. (3) Processes directly aware of each  other: These are processes that are able to communicate with each  other by process ID and which are designed to work jointly on some  activity.

**5.5. What is the distinction between competing processes and cooperating processes?** Competing processes need access to the same resource at the same  time, such as a disk, file, or printer. Cooperating processes either  share access to a common object, such as a memory buffer or are able  to communicate with each other, and cooperate in the performance of  some application or activity. 

**5.6. List the three control problems associated with competing processes, and briefly define  each.** (1) Mutual exclusion: competing processes can only access a resource  that both wish to access one at a time; mutual exclusion mechanisms  must enforce this one-at-a-time policy.  (2) Deadlock: if competing  processes need exclusive access to more than one resource then  deadlock can occur if each processes gained control of one resource and  is waiting for the other resource. (3) Starvation: one of a set of competing  processes may be indefinitely denied access to a needed resource  because other members of the set are monopolizing that resource. 

**5.7. What is starvation with respect to concurrency control by mutual exclusion?** Starvation refers to a situation where a runnable process is infinitely overlooked by the scheduler for performance of a certain activity. In the context of concurrency control using mutual exclusion, this situation occurs when many processes are contending to enter in the critical section and a process is indefinitely denied access. Although this process is ready to execute in its critical section, it is never chosen and as an outcome never runs to completion.

**5.8. What operations can be performed on a semaphore?** (1) A semaphore may be initialized to a nonnegative value.  (2) The wait operation decrements the semaphore value. If the value becomes  negative, then the process executing the wait is blocked.  (3) The signal operation increments the semaphore value. If the value is not positive,  then a process blocked by a wait operation is unblocked. 

**5.9. What is the difference between binary and general semaphores?** A binary semaphore may only take on the values 0 and 1. A general  semaphore may take on any integer value. 

**5.10. What is the key difference between a mutex and a binary semaphore?**The key difference between the two is that the process that locks a mutex must be the one to unlock it; in a semaphore implementation, however, if the operation wait(s) is executed by one process, the operation signal(s) can be executed by any process

**6.1. Give examples of reusable and consumable resources.** Examples of reusable resources are processors, I/O channels, main and  secondary memory, devices, and data structures such as files,  databases, and semaphores. Examples of consumable resources are  interrupts, signals, messages, and information in I/O buffers.

**6.2. What are the three conditions that must be present for deadlock to be possible?** (1) Mutual exclusion. Only one process may use a resource at a time.   (2) Hold and wait. A process may hold allocated resources while awaiting  assignment of others.  (3) No preemption. No resource can be forcibly  removed from a process holding it.

**6.3. What are the four conditions that create deadlock?** (1) Mutual exclusion. Only one process may use a resource at a time.   (2) Hold and wait. A process may hold allocated resources while awaiting  assignment of others.  (3) No preemption. No resource can be forcibly  removed from a process holding it. (4) Circular wait. A closed chain of  processes exists, such that each process holds at least one resource  needed by the next process in the chain.

**6.4. How can the hold-and-wait condition be prevented?**  The hold-and-wait condition can be prevented by requiring that a  process request all of its required resources at one time, and blocking  the process until all requests can be granted simultaneously. 

**6.5. Why can’t you disallow mutual exclusion in order to prevent deadlocks?** Mutual exclusion restricts the usage of a resource to one user at a time. If mutual exclusion is disallowed, then all non-sharable resources become sharable. While this may not hamper some activities (like a read-only file being accessed by a number of users), it poses serious problems for activities that require non-sharable resources (like writing to a file). Preventing mutual exclusion in these situations gives undesirable results. Also, there are some resources (like printers) that are inherently non-sharable, and it is impossible to disallow mutual exclusion. Thus, in general, mutual exclusion cannot be disallowed for practical purposes.

**6.6. How can the circular wait condition be prevented?** The circular-wait condition can be prevented by defining a linear  ordering of resource types. If a process has been allocated resources of  type R, then it may subsequently request only those resources of types  following R in the ordering.

**6.7. List some of the methods that may be adopted to recover from deadlocks.**(1) Abort all deadlocked processes. Though this is a common solution adopted in operating systems, the overhead is very high in this case. (2) Back up each deadlocked process to some previously defined checkpoint and restart all processes. (3) Detect the deadlocked processes in a circular-wait condition. Successively abort deadlocked processes until the circular wait is eliminated and the deadlock no longer exists. (4) Successively preempt resources until the deadlock no longer exists

**7.1. What requirements is memory management intended to satisfy?** Relocation, protection, sharing, logical organization, physical  organization.

**7.2. What is relocation of a program?** To relocate a program is to load and execute a given program to an arbitrary place in the memory; therefore, once a program is swapped out to the disk, it may be swapped back anywhere in the main memory.

**7.3. What are the advantages of organizing programs and data into modules?** (1) Modules can be written and compiled independently. All references from one module to another can be resolved by the system at run time. (2) Each module can be given different degrees of protection (like read only, read-write, execute only, read-write-execute, etc.). The overhead associated with this is quite nominal. (3) A module can be shared among different processes by incorporating appropriate
mechanisms.

**7.4. What are some reasons to allow two or more processes to all have access to a particular  region of memory?**If a number of processes are executing the same program, it is  advantageous to allow each process to access the same copy of the  program rather than have its own separate copy. Also, processes that  are cooperating on some task may need to share access to the same  data structure.

**7.6. What is the difference between internal and external fragmentation?**Internal fragmentation refers to the wasted space internal to a partition  due to the fact that the block of data loaded is smaller than the  partition. External fragmentation is a phenomenon associated with dynamic partitioning, and refers to the fact that a large number of small  areas of main memory external to any partition accumulates. 

**7.8. What is the difference between a page and a frame?** In a paging system, programs and data stored on disk or divided into  equal, fixed-sized blocks called pages, and main memory is divided into  blocks of the same size called frames. Exactly one page can fit in one  frame.

**7.9. What is the difference between a page and a segment?**An alternative way in which the user program can be subdivided is  segmentation. In this case, the program and its associated data are  divided into a number of segments. It is not required that all segments  of all programs be of the same length, although there is a maximum  segment length. 

**7.5. Another placement algorithm for dynamic partitioning is referred to as worst-fit. In  this case, the largest free block of memory is used for bringing in a process.** 

**a. Discuss the pros and cons of this method compared to first-, next-, and best-fit.** A criticism of the best-fit algorithm is that the space remaining after  allocating a block of the required size is so small that in general it is  of no real use. The worst fit algorithm maximizes the chance that the  free space left after a placement will be large enough to satisfy  another request, thus minimizing the frequency of compaction. The  disadvantage of this approach is that the largest blocks are allocated  first; therefore a request for a large area is more likely to fail.

**b. What is the average length of the search for worst-fit?** Same as best fit. 

**7.7. A 1-Mbyte block of memory is allocated using the buddy system.** 

**a. Show the results of the following sequence in a figure similar to Figure 7.6 : Request 70; Request 35; Request 80; Return A; Request 60; Return B; Return D; Return C.** 

**b. Show the binary tree representation following Return B.**

**7.12. Consider a memory-management system based on paging. The total size of the physical  memory is 2 GB, laid out over pages of size 8 KB. The logical address space of each  process has been limited to 256 MB. **

**a. Determine the total number of bits in the physical address. **We have total size of physical memory as 2GB. This means that $2^1\times2^{30}=2^{31}$. So physical address is equal to 31 bits

**b. Determine the number of bits specifying page replacement and the number of bits  for page frame number. **We get page size = 8kb = $2^3$. 1 kb = $2^{10}$. $2^3\times2^{10}=2^{13}$. So page replacement = 13 bits. Page frame number = physical address - replacement bits = 31 - 13 = 18 bits.

**c. Determine the number of page frames. **The number of frames is given as $2^{18}=2^{8}\times2^{10}$ = 256K. So number of frames = 256K

**d. Determine the logical address layout.**Logical add space is 256K. Page size= physical pages = 8kb. Logical address layout= 28bits. Page number = 15 bits. Displacement = 12 bits. 256k/8k = 32 pages in address space process.

**8.1. How does the use of virtual memory improve system utilization?** (1) More processes may be maintained in main memory: The use of virtual memory allows the loading of only portions of a process into the main memory. Therefore, more processes can enter the system, thus resulting in higher CPU utilisation. (2) A process may be larger than all of main memory: The use of virtual memory theoretically allows a process to be as large as the disk storage available, however, there will be system constraints (such as address space) that will limit the size

**8.2. Explain thrashing.** Thrashing is a phenomenon in virtual memory schemes, in which the  processor spends most of its time swapping pieces rather than  executing instructions.

**8.3. Why is the principle of locality crucial to the use of virtual memory?** Algorithms can be designed to exploit the principle of locality to avoid  thrashing. In general, the principle of locality allows the algorithm to  predict which resident pages are least likely to be referenced in the near  future and are therefore good candidates for being swapped out. 

**8.4. Which considerations determine the size of a page?** (1) Page size versus page table size (2) Page size versus TLB usage (3) Internal fragmentation of pages (4) Page size versus disk access

**8.5. What is the purpose of a translation lookaside buffer?**The TLB is a cache that contains those page table entries that have  been most recently used. Its purpose is to avoid, most of the time,  having to go to disk to retrieve a page table entry.

**8.7. What are the drawbacks of using either only a precleaning policy or only a demand  cleaning policy?** Cleaning refers to determining when a modified page should be written out to secondary memory. Two common cleaning policies are demand cleaning and pre-cleaning. There are problems with using either of the two policies exclusively. This is because, on the one hand, pre-cleaning involves a page being written out but remaining in the main memory until the page replacement algorithm dictates that it can be removed. Therefore, while precleaning allows the writing of pages in batches, it makes little sense to write out hundreds or thousands of pages only to find that the majority of them have been modified again before they are replaced. The transfer capacity of secondary memory is limited in this method; it is wasted in unnecessary cleaning operations. On the other hand, with demand cleaning, the writing of a dirty page is coupled to, and precedes, the reading in of a new page. This technique may minimise page writes, but it results in the fact that a process that suffers a page fault may have to wait for two-page transfers before it can be unblocked. This may decrease processor utilisation

**8.8. What is the relationship between FIFO and clock page replacement algorithms?** The clock policy is similar to FIFO, except that in the clock policy, any  frame with a use bit of 1 is passed over by the algorithm.

**8.9. How is a page fault trap dealt with?** (1) The memory address requested is first checked, to make sure it was a valid memory request. (2) If the reference was invalid, the process is terminated. Otherwise, the page must be paged in. (3) A free frame is located, possibly from a free-frame list. (4) A disk operation is scheduled to bring in the necessary page from disk. ( This will usually block the process on an I/O wait, allowing some other process to use the CPU in the meantime. ) (5) When the I/O operation is complete, the process's page table is updated with the new frame number, and the invalid bit is changed to indicate that this is now a valid page reference. (6) The instruction that caused the page fault must now be restarted from the beginning, ( as soon as this process gets another turn on the CPU. )

**8.11. What is the difference between a resident set and a working set?**The resident set of a process is the current number of pages of that  process in main memory. The working set of a process is the number  of pages of that process that have been referenced recently. 

**8.1. Suppose the page table for the process currently executing on the processor looks like the following. All numbers are decimal, everything is numbered starting from zero, and all addresses are memory byte addresses. The page size is 1,024 bytes.**

**a. Describe exactly how, in general, a virtual address generated by the CPU is translated into a physical main memory address.**  Split binary address into virtual page number and offset; use VPN as  index into page table; extract page frame number; concatenate  offset to get physical memory address

**b. What physical address, if any, would each of the following virtual addresses correspond to? (Do not try to handle any page faults, if any.)**

**(1) 1,052** 1052 = 1024 + 28 maps to VPN 1 in PFN 7, (7 × 1024+28 =  7196)

**(2) 2,221**  2221 = 2 × 1024 + 173 maps to VPN 2, page fault 

**(3) 5,499** 5499 = 5 × 1024 + 379 maps to VPN 5 in PFN 0, (0 × 1024+379  = 379)

**8.4. Consider the following page-reference string: a, b, d, c, b, e, d, b, d, b, a, c, b, c, a, c, f,  a, f, d. Assume that there are 3 frames available and that they are all initially empty.  Complete a figure, similar to Figure 8.14, showing the frame allocation for each of the  following page replacement policies: **

**a. First-in-first-out b. Optimal c. Least recently used**



**8.6. A process contains eight virtual pages on disk and is assigned a fixed allocation of four page frames in main memory. The following page trace occurs: ** **1, 0, 2, 2, 1, 7, 6, 7, 0, 1, 2, 0, 3, 0, 4, 5, 1, 5, 2, 4, 5, 6, 7, 6, 7, 2, 4, 2, 7, 3, 3, 2, 3**

**a. Show the successive pages residing in the four frames using the LRU replacement policy. Compute the hit ratio in main memory. Assume the frames are initially empty. **

LRU: Hit ratio = 16/33

**b. Repeat part (a) for the FIFO replacement policy. **

FIFO: Hit ratio = 16/33

**c. Compare the two hit ratios and comment on the effectiveness of using FIFO to approximate LRU with respect to this particular trace.**These two policies are equally effective for this particular page trace. 

**8.17. Assume a task is divided into four equal-sized segments, and the system builds an eightentry page descriptor table for each segment. Thus, the system has a combination of segmentation and paging. Assume also the page size is 2 kB. **

**a. What is the maximum size of each segment? **8 × 2K = 16K

**b. What is the maximum logical address space for the task? ** 16K × 4 = 64K

**c. Assume an element in physical location 00021ABC is accessed by this task. What is the format of the logical address that the task generates for it? What is the maximum physical address space for the system?**$2^{32}=4$ GBytes

**8.18. Consider the following sequence of page references: A, B, B, C, A, E, D, B, D, E, A, C, E, B, A, C, A, F, D, F and consider that a working set strategy is used for page replacement. What will the  contents of the working set at each stage be for the following? **

**a. Window Size = 2 **

**b. Window Size = 3 **

**c. Window Size = 4**

**9.1. How is processor scheduling done in the batch portion of an OS?** Processor scheduling in a batch system, or in the batch portion of an OS, is done by a longterm scheduler. Newly submitted jobs are routed to disk and held in a batch queue from which the long-term scheduler creates processes and then places these in the ready queue so that they can be executed.

**9.5. Identify the advantages and disadvantages of preemptive scheduling.** Advantages: (1) It ensures fairness to all processes regardless of their priority in most cases. (2) It reduces the monopolisation of the CPU by a large process. (3) It increases the scheduling capacity of the system. (4) Depending on the CPU time the process needs, it also gives a quick response time for processes.

Disadvantages: (1) Pre-emption is associated with extra overhead due to increased contextswitch, increased caching, increased bus-related costs etc. (2) Pre-emptive scheduling results in increased dispatcher activities and, subsequently, more time for dispatching.

**9.6. Briefly define FCFS scheduling.** As each process becomes ready, it joins the ready queue. When the  currently-running process ceases to execute, the process that has been  in the ready queue the longest is selected for running. 

**9.7. Briefly define round-robin scheduling.**  A clock interrupt is generated at periodic intervals. When the interrupt  occurs, the currently running process is placed in the ready queue, and  the next ready job is selected on a FCFS basis. 

**9.8. Briefly define shortest-process-next scheduling.** This is a nonpreemptive policy in which the process with the shortest  expected processing time is selected next. 

**9.9. Briefly define shortest-remaining-time scheduling.** This is a preemptive version of SPN. In this case, the scheduler always  chooses the process that has the shortest expected remaining  processing time. When a new process joins the ready queue, it may in  fact have a shorter remaining time than the currently running process.  Accordingly, the scheduler may preempt whenever a new process  becomes ready. 

**9.10. Briefly define highest-response-ratio-next scheduling.** When the current process completes or is blocked, choose the ready  process with the greatest value of R, where R = (w + s)/s, with w =  time spent waiting for the processor and s = expected service time.

**9.11. Briefly define feedback scheduling.**Scheduling is done on a preemptive (at time quantum) basis, and a  dynamic priority mechanism is used. When a process first enters the  system, it is placed in RQ0 (see Figure 9.4). After its first execution,  when it returns to the Ready state, it is placed in RQ1. Each  subsequent time that it is preempted, it is demoted to the next lowerpriority queue. A shorter process will complete quickly, without  migrating very far down the hierarchy of ready queues. A longer  process will gradually drift downward. Thus, newer, shorter processes  are favored over older, longer processes. Within each queue, except  the lowest-priority queue, a simple FCFS mechanism is used. Once in  the lowest-priority queue, a process cannot go lower, but is returned  to this queue repeatedly until it completes execution. 

**9.3. Consider that a uniprocessor system has n processes to be scheduled. If only nonpreemptive scheduling algorithms are allowed, can you determine the maximum number  of possible schedules in terms of n?**Uniprocessor can have only one process at a time i.e it takes one process at a time and completes. Since in case of non premptive scheduling ,process can not be prempted until it completes its execution. Possibility of Scheduling the n process is as follows : 1st st Process can be executed in n ways , 2nd Process can be execute in (n-1) ways , 3rd Process can be executed in (n-2) ways ... (n-1)th Process can be executed in 2 ways , nth Process can be executed in 1 ways.  Total number of possible ways=n*(n-1)*(n-2)*(n-3).........2.1 =n! . So ,total number of possible way to schedule process in non premptive mode in uniprocessor=n!

**9.7. In a nonpreemptive uniprocessor system, the ready queue contains three jobs at time t immediately after the completion of a job. These jobs arrived at times and with estimated execution times of and respectively. Figure 9.18 shows the linear increase of their response ratios over time. Use this example to find a variant of response ratio scheduling, known as minimax response ratio scheduling, that minimizes the maximum response ratio for a given batch of jobs ignoring further arrivals. (Hint: Decide, first, which job to schedule as the last one.)**First, the scheduler computes the response ratios at time t + r1 + r2 +  r3, when all three jobs will have been finished (see figure). At that time,  job 3 will have the smallest response ratio of the three: so the scheduler  decides to execute this job last and proceeds to examine jobs 1 and 2 at time t + r1 + r2, when they will both be finished. Here the response  ratio of job 1 is ,the smaller, and consequently job 2 is selected for  service at time t. This algorithm is repeated each time a job is  completed to take new arrivals into account. Note that this algorithm is  not quite the same as highest response ratio next. The latter would  schedule job 1 at time t. Intuitively, it is clear that the present algorithm  attempts to minimize the maximum response ratio by consistently  postponing jobs that will suffer the least increase of their response  ratios.


**9.16. Five batch jobs, A through E, arrive at a computer center at essentially the same time. They have an estimated running time of 15, 9, 3, 6, and 12 minutes, respectively. Their (externally defined) priorities are 6, 3, 7, 9, and 4, respectively, with a lower value corresponding to a higher priority. For each of the following scheduling algorithms, determine the turnaround time for each process and the average turnaround for all jobs. Ignore process switching overhead. Explain how you arrived at your answers. In the last three cases, assume only one job at a time runs until it finishes, and all jobs are completely processor bound. **

**a. round robin with a time quantum of 1 minute **Sequence with which processes will get 1 min of processor time: The turnaround time for each process:  A = 45 min, B = 35 min, C = 13 min, D = 26 min, E = 42 min The average turnaround time is = (45+35+13+26+42) / 5 = 32.2 min

**b. priority scheduling **The average turnaround time is: (9+21+36+39+45) / 5 = 30 min

**c. FCFS (run in order 15, 9, 3, 6, and 12) **The average turnaround time is: (15+24+27+33+45) / 5 = 28.8 min

**d. shortest job first**The average turnaround time is: (3+9+18+30+45) / 5 = 21 min

**10.1. List and briefly define five different categories of synchronization granularity.** (1) Fine: Parallelism inherent in a single instruction stream.  (2) Medium: Parallel processing or multitasking within a single application.  (3) Coarse: Multiprocessing of concurrent processes in a multiprogramming  environment.  (4) Very Coarse: Distributed processing across network  nodes to form a single computing environment. (5) Independent: Multiple unrelated processes.

**10.2. What grain size of parallelism is appropriate for a multiprogrammed uniprocessor?** Coarse grained or very coarse grained parallelisms are appropriate for a multiprogrammed uniprocessor. In this situation the synchronisation between processes is at a very gross level. Thus, it can easily be handled as a set of concurrent processes whose interaction among themselves is limited. The processes get CPU time in the uniprocessor system in accordance with any scheduling algorithm they might use.

**10.3. For which kinds of applications is gang scheduling of threads most useful?**Gang scheduling is most useful for medium-grained to fine-grained parallel applications whose performance severely degrades when any part of the application is not running while other parts are ready to run. It is also beneficial for any parallel application, even one that is not performance sensitive.

**11.3. What is the difference between block-oriented devices and stream-oriented devices?  Give a few examples of each.** Block-oriented devices stores information in blocks that are usually  of fixed size, and transfers are made one block at a time. Generally, it  is possible to reference data by its block number. Disks and tapes are  examples of block-oriented devices. Stream-oriented devices  transfer data in and out as a stream of bytes, with no block structure.  Terminals, printers, communications ports, mouse and other pointing  devices, and most other devices that are not secondary storage are  stream oriented.

**11.5. State some utilities of buffering.**Buffering is a technique that smoothes out peaks in I/O demand. However, no amount of buffering will allow an I/O device to keep pace with a process indefinitely when the average demand of the process is greater than the I/O device can service. Even with multiple buffers, all of the buffers will eventually fill up, and the process will have to wait after processing each chunk of data. However, in a multiprogram- ming environment, when there is a variety of I/O activity and a variety of process activity to service, buffering is one tool that can increase the efficiency of the OS and the performance of individual processes.

**11.7. Calculate how much disk space (in sectors, tracks, and surfaces) will be required to store 300,000 120-byte logical records if the disk is fixed sector with 512 bytes/sector, with 96 sectors/track, 110 tracks per surface, and 8 usable surfaces. Ignore any file header record(s) and track indexes, and assume that records cannot span two sectors.**Each sector can hold 4 logical records. The required number of sectors  is 300,000/4 = 75,000 sectors. This requires 75,000/96 = 782 tracks,  which in turn requires 782/110 = 8 surfaces. 

**11.8. Consider the disk system described in Problem 11.7 , and assume the disk rotates at 360 rpm. A processor reads one sector from the disk using interrupt-driven I/O, with one interrupt per byte. If it takes to process each interrupt, what percentage of the time will the processor spend handling I/O? (disregard seek time)**There are 512 bytes/sector. Since each byte generates an interrupt,  there are 512 interrupts. Total interrupt processing time = 2.5 × 512 =  1280 µs. The time to read one sector is:  ((60 sec/min) / (360 rev/min)) / (96 sectors/track)  = 0.001736 sec = 1736 µs  Percentage of time processor spends handling I/O:  (100) × (1280/1736) = 74%

**12.1. What are the desirable properties of a file system?** A field is the basic element of data containing a single value. A  record is a collection of related fields that can be treated as a unit by  some application program. 

**12.2. What is the difference between a file and a database?** A file is a collection of similar records, and is treated as a single entity  by users and applications and may be referenced by name. A  database is a collection of related data. The essential aspects of a  database are that the relationships that exist among elements of data  are explicit and that the database is designed for use by a number of  different applications.

**12.3. What is a file management system?** A file management system is that set of system software that provides  services to users and applications in the use of files. 

**12.4. What criteria are important in choosing a file organization?** Rapid access, ease of update, economy of storage, simple  maintenance, reliability. 

**12.5. What are some advantages and disadvantages of sequential file organization?**Advantages: (1) Simplicity of organization. (2) Ease of access to adjacent records. (3) Simplicity of retrieval algorithms that may require additional data structure. (4) Fast retrieval of sequential data based on the primary key. (5) Creation of automatic backup copy. Disadvantages: (1) The average access time is equal to the time required to access half the file. (2) Even simple queries are time consuming. (3) Insertion of records mid-way is time consuming because it requires shifting all records after the inserted record in order to maintain the physical order of the system. (4) Record deletion results in a wastage of space and is therefore not a problem-free alternative to shifting records

**12.2. One scheme to avoid the problem of preallocation versus waste or lack of contiguity is to allocate portions of increasing size as the file grows. For example, begin with a portion size of one block, and double the portion size for each allocation. Consider a file of n records with a blocking factor of F, and suppose a simple one-level index is used as a file allocation table. **

**a. Give an upper limit on the number of entries in the file allocation table as a function of F and n. **$\log_2\frac{N}{F}$

**b. What is the maximum amount of the allocated file space that is unused at any time?**Less than half the allocated file space is unused at any time.

**12.4. For the B-tree in Figure 12.4c , show the result of inserting the key 97.**The result is identical to Figure 12.5 d, except for the following: At the  lowest level, the rightmost block contains 90, 96, 97. The block to the  left of the rightmost block contains 73, 85. 

**12.9. Fragmentation of a disk can be removed by the process of compaction. Compaction  involves a relocation of the files. But disks do not have relocation registers or base  registers. How, then, can files be relocated in a disk?**(1) Disk fragmentation is a common problem that occurs when files on a disk become fragmented and spread out over multiple physical locations on the disk. This can cause a significant slowdown in the performance of the disk, as the read/write heads of the disk have to move around more frequently to access the different parts of the file. To address this problem, the process of compaction can be used to relocate the fragmented files to contiguous blocks on the disk, thereby improving disk performance. The process of compaction involves moving the data from its current location to a new location on the disk. However, as disks do not have relocation registers or base registers, the data cannot be relocated directly. Instead, the data is relocated using a technique known as file copying. (2) File copying involves reading the data from its current location and writing it to a new location on the disk. This new location is chosen to be contiguous with the rest of the file, so that the file becomes a single contiguous block on the disk. Once the file has been copied to its new location, the file allocation table (FAT) is updated to reflect the new location of the file. The FAT is a table that maps the logical addresses of files on the disk to their physical locations on the disk. The process of file copying can be time-consuming, especially if there are many fragmented files on the disk. Additionally, if there is not enough contiguous space on the disk to accommodate the relocated files, then the compaction process may not be successful. To address these issues, various optimization techniques can be used to improve the efficiency of the compaction process. (3) One such technique is the use of a partial compaction algorithm, which only compacts a portion of the disk at a time, rather than the entire disk. This can help to reduce the time required for the compaction process, as well as the amount of disk space required to temporarily store the relocated files. Another technique is the use of a priority-based compaction algorithm, which prioritizes the compaction of files that are frequently accessed or that are critical to the operation of the system. This can help to improve the overall performance of the system by ensuring that the most important files are located in contiguous blocks on the disk.  Final answer : In conclusion, while disks do not have relocation registers or base registers, fragmented files can still be relocated on a disk through the process of file copying. Although the process of compaction can be time-consuming, various optimization techniques can be used to improve the efficiency of the process and ensure that the most important files are located in contiguous blocks on the disk.

**12.11. Consider a hierarchical file system in which free disk space is kept in a free space list.**

**a. Suppose the pointer to free space is lost. Can the system reconstruct the free space list? **Yes. the method employed is very similar to that used by many  LISP systems for garbage collection. First we would establish a data structure representing every block on a disk supporting a file  system. A bit map would be appropriate here. Then, we would  start at the root of the file system (the "/" directory), and mark  every block used by every file we could find through a recursive  descent through the file system. When finished, we would create a  free list from the blocks remaining as unused. This is essentially  what the UNIX utility fsck does. 

**b. Suggest a scheme to ensure that the pointer is never lost as a result of a single memory failure.**Keep a "backup" of the free-space list pointer at one or more  places on the disk. Whenever this beginning of the list changes,  the "backup" pointers are also updated. This will ensure you can  always find a valid pointer value even if there is a memory or disk  block failure. 