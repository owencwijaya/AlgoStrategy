#gakuat mental ngegabunginnya jadi pake py sj
#sementara baru bisa matriks yang kotak dan ukurannya genap yes

import numpy

def split(matrix):
    # membagi matriks jadi 4 bagian sama besar
    row, col = matrix.shape
    midRow = row // 2
    midCol = col // 2
    upperLeftMat = matrix[:midRow, :midCol]
    upperRightMat = matrix[:midRow, midCol:]
    lowerLeftMat = matrix[midRow:, :midCol]
    lowerRightMat = matrix[midRow:, midCol:]
    return upperLeftMat, upperRightMat, lowerLeftMat, lowerRightMat

        
#A, B: matriks, n: ukuran matriks
def strassenMult(A, B, n):
    #kalau ukuran matriks 1 x 1, langsung return mat1 * mat2
    if (n == 1):
        return A * B

    #kalau ukuran matriks tidak sama, split matriksnya
    A11, A12, A21, A22 = split(A) 
    B11, B12, B21, B22 = split(B)

    C11 = strassenMult(A11, B11, n // 2) + strassenMult(A12, B21, n // 2)
    C12 = strassenMult(A11, B12, n // 2) + strassenMult(A12, B22, n // 2)
    C21 = strassenMult(A21, B11, n // 2) + strassenMult(A22, B21, n // 2)
    C22 = strassenMult(A21, B12, n // 2) + strassenMult(A22, B22, n // 2)

    C = numpy.vstack((numpy.hstack((C11, C12)), numpy.hstack((C21, C22))))
    return C

MatrixA = numpy.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
MatrixB = numpy.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
print(strassenMult(MatrixA, MatrixB, 4))

# [[ 90 100 110 120]
#  [202 228 254 280]
#  [314 356 398 440]
#  [426 484 542 600]]