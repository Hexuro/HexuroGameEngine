import os
import sys
import shutil

print("Working directory: " + sys.argv[0])
config = sys.argv[1]
print("Configuration: " + sys.argv[1])
projname = sys.argv[2]
os.makedirs("./../bin/" + config + "/Sandbox", exist_ok=True)

for filename in os.listdir("Assets"):
    assets_path = os.path.join("Assets", filename)
    destination_path = os.path.join("./../bin/" + config + "/" + projname, filename)
    
    if os.path.isfile(assets_path):
        shutil.copy(assets_path, destination_path)
        print(f'Copy: {filename}')
