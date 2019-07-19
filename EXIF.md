http://www.linux-magazine.com/Online/Blogs/Productivity-Sauce/Remove-EXIF-Metadata-from-Photos-with-exiftool

       exiftool -all= dst.jpg
            Delete all meta information from an image.  Note: You should NOT do this to RAW images (except DNG) since proprietary RAW image formats often contain information
            in the makernotes that is necessary for converting the image.

       exiftool -all= -comment='lonely' dst.jpg
            Delete all meta information from an image and add a comment back in.  (Note that the order is important: "-comment='lonely' -all=" would also delete the new
            comment.)

       exiftool -all= --jfif:all dst.jpg
            Delete all meta information except JFIF group from an image.

