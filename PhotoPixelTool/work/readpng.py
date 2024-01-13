from PIL import Image
import os
import numpy as np

exeFileName = "writepixel_bitfile.exe"
scrDirName = "data"
bufferDirName = "buffer"
outDirName = "out"

oldScrDirName = "old"

dadDir = os.path.dirname(__file__)
scrDir = os.path.join(dadDir, scrDirName)
bufferDir = os.path.join(dadDir, bufferDirName)
outDir = os.path.join(dadDir, outDirName)

oldScrDir = os.path.join(scrDir, oldScrDirName)

exeFilePath = os.path.join(dadDir, exeFileName)


def getPixel(imgPath, RGBdataPath):
    "将输入图像文件的RGB值读出到TXT文件中"

    image = Image.open(imgPath)
    # rgbimg = image.convert("RGB")
    rgbimg = image
    pixels = np.asarray(rgbimg, "uint32")
    pixelRGB = pixels[:, :, 0] * 65536 + pixels[:, :, 1] * 256 + pixels[:, :, 2]

    # 将像素输出为txt文件
    np.savetxt(RGBdataPath, pixelRGB, delimiter="\t", fmt="%d")


if __name__ == "__main__":
    # 获取数据文件
    imgList = os.listdir(scrDir)

    # 将scrDir中全部图片解析为可直接使用的同名无后缀数据文件到outDir中去
    for imgName in imgList:

        imgPath = os.path.join(scrDir, imgName)
        if os.path.isfile(imgPath):
            print("\n对%s进行解析\n" % imgPath)
            imgBaseName = os.path.splitext(imgName)[0]  # 去除后缀
            RGBtxtPath = os.path.join(bufferDir, imgBaseName+".txt")

            # 读取图片像素, 获取RGB编码
            getPixel(imgPath, RGBtxtPath)

            # 调用exe文件将txt文件转化为可读取文件,输出到out中
            outFilePath = os.path.join(outDir, imgBaseName)
            exeReturn = os.system(" ".join([exeFilePath, RGBtxtPath, outFilePath]))
            if exeReturn == 1:
                print("解析失败，退出python程序，请检查源文件名称是否正确\n")
                exit(1)
            else:
                # 将转换后图片文件移动到oldScrDir中去
                os.rename(imgPath, os.path.join(oldScrDir, imgName))
        else:
            continue

    print("\n完成%s中所有图片文件的转换\n" % scrDir)
