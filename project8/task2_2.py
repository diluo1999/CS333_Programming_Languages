'''
CS333 Project 8 
task3.py
Program that reads an image and applies a pixel-wise operator to it

Di Luo
05/15/2020
'''
import sys
import time
import threading
import pyppmIO

class imageThread(threading.Thread):
    def __init__(self, start, end, colidx,data):
        threading.Thread.__init__(self)
        self.start = start
        self.extend = end
        self.col = colidx
        self.data = data

    def run(self):
        for row in range(self.start, self.start+self.extend):
            for col in range(0, self.col):
                start = row * self.col * 3 + col * 3
                end = start + 3
                r,g,b = self.data[start:end]
                g = (r+g+b)/3
                self.data[start:end] = g, g, g

def main(argv):
    ppm = pyppmIO.PPM(argv[1])
    rows = ppm.rows
    cols = ppm.cols
    data = ppm.data

    thread1 = imageThread(0, rows, cols,data)

    thread2_1 = imageThread(0, rows//2, cols,data)
    thread2_2 = imageThread(rows//2, rows//2, cols,data)

    thread4_1 = imageThread(0, rows//4, cols,data)
    thread4_2 = imageThread(rows//4, rows//4, cols,data)
    thread4_3 = imageThread(rows//2, rows//4, cols,data)
    thread4_4 = imageThread(rows//2+rows//4, rows//4, cols,data)

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
    t2 = time.process_time()
    t = t2-t1
    print(f'Time of 4 threads in seconds: {t}.')

if __name__ == "__main__":
   main(sys.argv)