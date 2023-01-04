# -*- coding: utf-8 -*-
"""
Created on Mon Nov 14 18:08:37 2022

Comparison of execution times between the DFT and the FFT.  The time
complexity of the DFT is O(N^2) while the time complexity of the FFT
is O(N*logN)

@author: mxz50
"""
import numpy as np
from matplotlib import pyplot as plt 
from scipy.fftpack import fft,ifft
import scipy
import math
import random
import timeit
from mpl_toolkits.mplot3d import Axes3D

def main():
    pnts=10000
    signal=np.random.randn(pnts)
    
    tic=timeit.default_timer()
    
    fourTime=np.arange(pnts)/pnts
    fCoefs=np.zeros(pnts,dtype=complex)
    for fi in range(pnts):
        csw=np.exp(-2j*np.pi*fi*fourTime)
        fCoefs[fi]=np.dot(signal,csw)
    toc=timeit.default_timer()
    t1=toc-tic
    print("DFT: ",t1)
    
    tic=timeit.default_timer()
    Xf=fft(signal)
    toc=timeit.default_timer()
    t2=toc-tic
    print("FFT: ",t2)
    
    plt.bar([1,2],[t1,t2])
    plt.title('Computation times')
    plt.ylabel('Time (sec)')
    plt.xticks([1,2],['DFT','FFT'])
    plt.show()
    
main()