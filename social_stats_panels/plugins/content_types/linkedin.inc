<?php

/**
 * @file
 * Returns a content type with number of LinkedIn shares of the node.
 * Only available on on node view i.e. with required context node being viewed
 */
$plugin = array(
  'title' => t('LinkedIn: shares count'),
  'content_types' => 'linkedin',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_linkedin_form_edit',
  'render callback' => 'social_stats_linkedin_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

/**
 * Function to render the share count.
 */
function social_stats_linkedin_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $shares_count = db_select('social_stats_linkedin', 'l')
                  ->fields('l')
                  ->condition('l.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if ($shares_count->linkedin_shares == '1') {
    $block->content = $shares_count->linkedin_shares . ' share';
  }
  else {
    $block->content = $shares_count->linkedin_shares . ' shares';
  }  
  return $block;
}

/**
 * Function to render the edit form, if not used doesn't get a form at all.
 */
function social_stats_linkedin_form_edit($form, &$form_state) {
  return $form;
}
