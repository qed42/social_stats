------------------------
SOCIAL STATS MODULE README
------------------------

This is a statistics module. It provides data from various social
media sites. The data which is saved per node includes data from:
1. Facebook    : likes count, shares count, comments count & total count.
2. Twitter     : tweets count.
3. LinkedIn    : share count.
4. Google Plus : plus one count

------------------------
MODULE STRUCTURE
------------------------

1. social_stats : This module is responsible to collect data from the
   social sites and store it in the database.
2. social_stats_views : Views integration of the data collected by
   social_stats module.

------------------------
REQUIREMENTS
------------------------

1. Social Stats : This module requires a supported version 
   of Drupal and cron to be running.
2. Social Stats Views : requires social stats and views 
   (http://drupal.org/project/views)

------------------------
INSTALLATION
------------------------

1. Clone the git repo into directory where you keep contributed modules
   (e.g. sites/all/modules/).

2. Enable the Social Stats module on the Modules list page.  The database
   tables will be created automagically for you at this point.

3. Modify permissions on the People >> Permissions page.

4. Go to admin/config/social-stats/settings, and select the social sites
   per content type.

5. Run cron. This will fetch the statistics per node and store it in database.

6. Enable the Social Stats Views module (can do it at step 2 itself).

------------------------
USAGE
------------------------

The administrative interface is at: Administer >> Configuration >>
Social Stats >> Social Stats settings.

Social Stats Views module will enable you to have the following additional
features to views.
1. Field : Add social statictics of node as field. Under "Add field",
   click on the category "Social Stats", and select the data.
2. Filter : Filter the content on the stats. For example, you can have a
   filter like "only show nodes which have Facebook likes > 200".
3. Sort : Sort the content on the basis of the stats, ascending or
   descending.
