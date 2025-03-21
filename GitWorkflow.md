git fetch from upstream

git merge upstream/<branch> -X ours

git ls-files -u | awk '{print $4}' | sort -u | xargs git rm

There are still files of theirs that gets added. We can remove it later if reqiuired. 

git commit -m :""
git push
