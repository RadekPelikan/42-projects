#!/bin/sh
find . -name \*.sh | xargs -I {} basename {} ".sh"