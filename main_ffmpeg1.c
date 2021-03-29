#include <libavutil/log.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

int main(int argc, char *argv[]) {
    av_log_set_level(AV_LOG_DEBUG);
    int ret;

    /*文件移动和删除*/
    /*ret = avpriv_io_move("./1.txt", "./2.txt");
    if (ret < 0) {
        return -1;
    }

    ret = avpriv_io_delete("./2.txt");
    if (ret < 0) {
        return -1;
    }*/

    /*读取文件夹信息*/
    AVIODirContext *avioDirContext;
    AVIODirEntry *avioDirEntry;
    ret = avio_open_dir(&avioDirContext, "./", NULL);
    if (ret < 0) {
        goto failContext;
    }

    while (1) {
        ret = avio_read_dir(avioDirContext, &avioDirEntry);
        if (ret < 0) {
            goto failEntry;
        }

        if (!avioDirEntry) {
            break;
        }

        av_log(NULL, AV_LOG_INFO, "%12"PRId64" %s \n",
                avioDirEntry->size,
                avioDirEntry->name);

        avio_free_directory_entry(&avioDirEntry);
    }

    failEntry:

    failContext:
    avio_close_dir(&avioDirContext);


    return 0;
}