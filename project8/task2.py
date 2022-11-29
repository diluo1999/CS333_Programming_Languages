'''
CS333 Project 8 
task2.py
Implements a function in Python that sorts an array with parallelism

Di Luo
05/15/2020
'''
import time
import threading
import numpy as np

class sortThread(threading.Thread):
    def __init__(self, start, end, array):
        threading.Thread.__init__(self)
        self.start_idx = start
        self.extend_idx = end
        self.array = array

    def run(self):
        self.array[self.start_idx : self.start_idx + self.extend_idx] = sorted(self.array[self.start_idx : self.start_idx + self.extend_idx])

def main():
    N = 100000
    arr = np.random.randint(0, 100000, 100000).tolist()

    thread1 = sortThread(0, N, arr)

    thread2_1 = sortThread(0, N//2, arr)
    thread2_2 = sortThread(N//2, N//2, arr)

    thread4_1 = sortThread(0, N//4, arr)
    thread4_2 = sortThread(N//4, N//4, arr)
    thread4_3 = sortThread(N//2, N//4, arr)
    thread4_4 = sortThread(N//2+N//4, N//4, arr)

    t1 = time.process_time()
    thread1.start()
    thread1.join()
    t2 = time.process_time()
    t = t2-t1
    print(f'Time of 1 thread in seconds: {t}.')

    t1 = time.process_time()
    thread2_1.start()
    thread2_1.join()
    thread2_2.start()
    thread2_2.join()
    arr = sorted(arr)
    t2 = time.process_time()
    t = t2-t1
    print(f'Time of 2 threads in seconds: {t}.')

    t1 = time.process_time()
    thread4_1.start()
    thread4_1.join()
    thread4_2.start()
    thread4_2.join()
    thread4_3.start()
    thread4_3.join()
    thread4_4.start()
    thread4_4.join()
    arr = sorted(arr)
    t2 = time.process_time()
    t = t2-t1
    print(f'Time of 4 threads in seconds: {t}.')

main()