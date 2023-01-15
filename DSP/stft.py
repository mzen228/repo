"""
Display a linear chirp in the time-domain, frequency-domain, and
the time-frequency domain
"""
from scipy.fftpack import fft
from matplotlib import pyplot as plt
import numpy as np

def computeSTFT(signal,win_length,step_size):
    N = len(signal)
    window = np.zeros(N)
    stft = np.zeros(N)

    for win_start in range(0, N, step_size):
        window = np.zeros(N)
        window[win_start:win_start + win_length] = 1
        x_window = signal * window
        x_window_fft = (2 / N) * abs(fft(x_window))
        stft = np.column_stack((stft, x_window_fft))

    return stft

def main():
    Fs = 1500
    t_res = 1/Fs
    t = np.arange(0,1,t_res)
    N = len(t)
    f_res = Fs/N
    f_axis = np.arange(0,Fs/2,f_res)
    fchirp = np.linspace(1, 40, N)
    x = np.sin(2 * np.pi * fchirp * t)
    Xf = (2/N) * abs(fft(x))

    spectrogram = computeSTFT(x,win_length=N//10,step_size=25)

    plt.figure()
    plt.plot(t,x)
    plt.title("Linear chirp in time-domain")
    plt.xlabel("Time (s)")
    plt.ylabel("Amplitude")
    plt.grid()
    plt.tight_layout()

    plt.figure()
    plt.plot(f_axis,Xf[:len(f_axis)])
    plt.title("Linear chirp in the frequency domain")
    plt.xlabel("Frequency (Hz)")
    plt.ylabel("Amplitude")
    plt.grid()
    plt.tight_layout()
    plt.xlim(0,120)

    plt.figure()
    plt.imshow(spectrogram,aspect="auto",origin="lower",cmap="gray")
    plt.title("Spectrogram of linear chirp")
    plt.xlabel("Time steps")
    plt.ylabel("Frequency (Hz)")
    plt.ylim(0,100)
    plt.tight_layout()
    plt.show()

main()