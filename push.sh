git add .
read -p 'Description of changes for commit: ' description

git commit -m "$description"
git push -u origin main

#commands
#git branch dev-irfan
#git push -u origin dev-irfan
#git checkout dev-irfan
