((nil . (
  (ssh-deploy-root-local . "/Users/yaya/Documents/HEP/Meeting/NTUHEP group meeting/TheHolyWar/7/A/")
  (ssh-deploy-root-remote . "/ssh:wuhsinyeh@ntugrid5.phys.ntu.edu.tw:~/A/")
  (ssh-deploy-async . 1)
  (ssh-deploy-on-explicit-save . 1)
  (ssh-deploy-script . (lambda() (let ((default-directory ssh-deploy-root-remote))(shell-command "bash compile.sh"))))
)))
