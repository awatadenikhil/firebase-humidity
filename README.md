# firebase-humidity
# Steps
1. create repository in github as firebase-humidity
2. Go to https://console.firebase.google.com/ and create a new project  with name firebase-humidity
3. Create a folder E:\Firebase_main\firebase-humidity and open terminal with same folder
4. execute> git clone https://github.com/awatadenikhil/firebase-humidity.git
5. execute> npm install -g firebase-tools  # if already not install globally
6. execute>  firebase login
7. execute> firebase init hosting
8. fill below infomation

            PS E:\Firebase_main\firebase-humidity> firebase init hosting

                ######## #### ########  ######## ########     ###     ######  ########
                ##        ##  ##     ## ##       ##     ##  ##   ##  ##       ##
                ######    ##  ########  ######   ########  #########  ######  ######
                ##        ##  ##    ##  ##       ##     ## ##     ##       ## ##
                ##       #### ##     ## ######## ########  ##     ##  ######  ########

            You're about to initialize a Firebase project in this directory:

            E:\Firebase_main\firebase-humidity

            ? Are you ready to proceed? Yes

            === Project Setup

            First, let's associate this project directory with a Firebase project.
            You can create multiple project aliases by running firebase use --add,
            but for now we'll just set up a default project.

            ? Please select an option: Use an existing project
            ? Select a default Firebase project for this directory: fir-humidity-8c9c7 (firebase-humidity)
            i  Using project fir-humidity-8c9c7 (firebase-humidity)

            === Hosting Setup

            Your public directory is the folder (relative to your project directory) that
            will contain Hosting assets to be uploaded with firebase deploy. If you
            have a build process for your assets, use your build's output directory.

            ? What do you want to use as your public directory? public
            ? Configure as a single-page app (rewrite all urls to /index.html)? Yes
            ? Set up automatic builds and deploys with GitHub? Yes
            +  Wrote public/index.html

            i  Detected a .git folder at E:\Firebase_main\firebase-humidity
            i  Authorizing with GitHub to upload your service account to a GitHub repository's secrets store.

            Visit this URL on this device to log in:
            https://github.com/login/oauth/authorize?client_id=89cf50f02ac6aaed3484&state=755462737&redirect_uri=http%3A%2F%2Flocalhost%3A9005&scope=read%3Auser%20repo%20public_repo

            Waiting for authentication...

            +  Success! Logged into GitHub as awatadenikhil

            ? For which GitHub repository would you like to set up a GitHub workflow? (format: user/repository) awatadenikhil/firebase-humidity

            +  Created service account github-action-952993662 with Firebase Hosting admin permissions.
            +  Uploaded service account JSON to GitHub as secret FIREBASE_SERVICE_ACCOUNT_FIR_HUMIDITY_8C9C7.
            i  You can manage your secrets at https://github.com/awatadenikhil/firebase-humidity/settings/secrets.

            ? Set up the workflow to run a build script before every deploy? Yes
            ? What script should be run before every deploy? npm ci && npm run build

            +  Created workflow file E:\Firebase_main\firebase-humidity\.github/workflows/firebase-hosting-pull-request.yml
            ? Set up automatic deployment to your site's live channel when a PR is merged? Yes
            ? What is the name of the GitHub branch associated with your site's live channel? main

            +  Created workflow file E:\Firebase_main\firebase-humidity\.github/workflows/firebase-hosting-merge.yml

            i  Action required: Visit this URL to revoke authorization for the Firebase CLI GitHub OAuth App:
            https://github.com/settings/connections/applications/89cf50f02ac6aaed3484
            i  Action required: Push any new workflow file(s) to your repo

            i  Writing configuration info to firebase.json...
            i  Writing project information to .firebaserc...
            i  Writing gitignore file to .gitignore...

            +  Firebase initialization complete!


# run locally and deploy 

execute below command to run locally

1. firebase serve                # to run the project
2. firebase deploy

# create realtime database

1. go to all project 
2. click on real time database
3. click on create database
4. select start with test mode
5. copy URL (https://fir-humidity-8c9c7-default-rtdb.firebaseio.com)


# deploy URL
https://fir-humidity-8c9c7.web.app
