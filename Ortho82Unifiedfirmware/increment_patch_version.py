from pathlib import Path
import os
import time
import argparse


ROOT_DIR = Path(__file__).parent
# print(ROOT_DIR)
version_file = os.path.join(
    ROOT_DIR,
    "Split82Firmware\\Split82Firmware\\src\\version.c"
)
# print(version_file)

PATCH_TEMPLATE = "const int PATCH = "
TIMESTAMP_TEMPLATE = "const char TIMESTAMP[20] = "


def increment_version(update_patch, update_timestamp) -> None:
    """Reads version file, update patch and timestamp, overwrite save."""

    if not (update_patch or update_timestamp):
        print("Nothing updated")
        return
    
    with open(version_file, "rt") as fp:
        version_content = fp.readlines()
    new_content = version_content.copy()
    for num, line in enumerate(version_content):

        if line.startswith(PATCH_TEMPLATE):
            print("Current:", line, sep="\n", end="")
            curr_patch = line.split()[-1][:-1]
            if update_patch:
                print("Updated:")
                new_patch = f"{PATCH_TEMPLATE}{int(curr_patch.strip()) + 1};\n"
                print(new_patch, end="")
                new_content[num] = new_patch
            
        if line.startswith(TIMESTAMP_TEMPLATE):
            print("Current:", line, sep="\n", end="")
            curr_timestamp = line.split()[-1][:-1]
            if update_timestamp:
                print("Updated:")
                formatted_timestamp = time.strftime("%Y-%m-%d_%H:%M:%S", time.localtime())
                new_timestamp = f"{TIMESTAMP_TEMPLATE}\"{formatted_timestamp}\";\n"
                print(new_timestamp, end="")
                new_content[num] = new_timestamp
            

    with open(version_file, "wt") as fw:
        fw.writelines(new_content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", default=False, help="Update Patch version")
    parser.add_argument("-t", default=False, help="Update Timestamp")
    
    args = parser.parse_args()

    increment_version(args.p, args.t)

    
