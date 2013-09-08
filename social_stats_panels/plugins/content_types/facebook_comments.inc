<?php

/**
 * @file
 * Returns a content type with number of facebook comments on the node.
 * Only available on on node view i.e. with required context node being viewed
 */

$plugin = array(
  'title' => t('Facebook Comments'),
  'content_types' => 'facebook_comments',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_facebook_comments_form_edit',
  'render callback' => 'social_stats_facebook_comments_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

/**
 * Function to render the comment count.
 */
function social_stats_facebook_comments_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $comments_count = db_select('social_stats_facebook', 'fb')
                  ->fields('fb')
                  ->condition('fb.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if ($comments_count->fb_comments == '1') {
    $block->content = $comments_count->fb_comments . ' comment';
  }
  else {
    $block->content = $comments_count->fb_comments . ' comments';
  }  
  return $block;
}

/**
 * Function to render the edit form, if not used doesn't get a form at all.
 */
function social_stats_facebook_comments_form_edit($form, &$form_state) {
  return $form;
}
